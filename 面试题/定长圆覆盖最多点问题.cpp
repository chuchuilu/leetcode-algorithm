#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

//

// Helper function to calculate distance between two points
double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

// Function to find maximum points covered by a circle with given radius
pair<double, double> findBestCenter(vector<pair<double, double>>& points, double r) {
    int maxCount = 0;
    pair<double, double> bestCenter;
    
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            double d = distance(points[i], points[j]);
            if (d > 2 * r) continue; // Skip if distance is more than diameter
            
            double midX = (points[i].first + points[j].first) / 2;
            double midY = (points[i].second + points[j].second) / 2;
            
            double h = sqrt(r * r - (d / 2) * (d / 2));
            double dx = (points[j].second - points[i].second) * h / d;
            double dy = (points[i].first - points[j].first) * h / d;
            
            pair<double, double> center1(midX + dx, midY + dy);
            pair<double, double> center2(midX - dx, midY - dy);
            
            int count1 = 0, count2 = 0;
            for (auto& p : points) {
                if (distance(p, center1) <= r) count1++;
                if (distance(p, center2) <= r) count2++;
            }
            
            if (count1 > maxCount) {
                maxCount = count1;
                bestCenter = center1;
            }
            if (count2 > maxCount) {
                maxCount = count2;
                bestCenter = center2;
            }
        }
    }
    
    return bestCenter;
}

int main() {
    vector<pair<double, double>> points = {{0, 0}, {2, 0}, {1, 1}, {4, 4}, {5, 1}};
    double radius = 2.0;
    pair<double, double> center = findBestCenter(points, radius);
    cout << "最佳圆心: (" << center.first << ", " << center.second << ")" << endl;
    return 0;
}
