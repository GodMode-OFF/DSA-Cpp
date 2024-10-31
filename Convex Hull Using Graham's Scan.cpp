#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Point {
    int x, y;
};

// A utility function to find the orientation of ordered triplet (p, q, r).
// Returns 0 if p, q and r are collinear, 1 if Clockwise, 2 if Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;           // collinear
    return (val > 0) ? 1 : 2;          // clockwise or counterclockwise
}

// A utility function to find the distance between two points
int distance(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// A comparator function used by sort() to sort points with respect to the first point
Point p0;
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) // If collinear, sort by distance
        return distance(p0, p1) < distance(p0, p2);
    return o == 2;
}

// Function to print the points of the convex hull
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull is not possible with fewer than 3 points." << endl;
        return;
    }

    // Find the bottom-most point
    int min_y = points[0].y, min_idx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < min_y) || (points[i].y == min_y && points[i].x < points[min_idx].x)) {
            min_y = points[i].y;
            min_idx = i;
        }
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min_idx]);
    p0 = points[0];

    // Sort the remaining points based on polar angle with p0
    sort(points.begin() + 1, points.end(), compare);

    // Create an empty stack and push first three points to it
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    // Process remaining points
    for (int i = 3; i < n; i++) {
        // Keep removing top while the angle between the next-to-top, top,
        // and points[i] makes a non-left turn
        while (hull.size() > 1) {
            Point q = hull.top();
            hull.pop();
            Point p = hull.top();
            if (orientation(p, q, points[i]) != 2) // If not left turn
                continue;
            hull.push(q); // Valid turn, push q back and break
            break;
        }
        hull.push(points[i]);
    }

    // Print the result
    cout << "Points in the convex hull are:\n";
    vector<Point> result;
    while (!hull.empty()) {
        Point p = hull.top();
        result.push_back(p);
        hull.pop();
    }

    // Optional: Sort for readability
    sort(result.begin(), result.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    for (auto p : result) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the points as x y:\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    convexHull(points);

    return 0;
}
