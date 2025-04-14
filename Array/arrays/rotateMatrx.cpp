

// problem:given a 2D array rotate it by 90 degree in clockwise direction (with out extra space)

// approach  : transpose and reverse

// transpose: mirros image from main diagonal. for inplace transpose

// for (int i = 0; i < n; ++i) {
//     for (int j = i+1; j < n; ++j) {
//         swap(matrix[i][j], matrix[j][i]);
//     }
// }


    // Reverse each row to achieve 90-degree rclockwise rotation for inplace  reverse

//     for (int i = 0; i < n; ++i) {
//         int left = 0, right = n - 1;
//         while (left < right) {
//             swap(matrix[i][left], matrix[i][right]);
//             ++left;
//             --right;
//         }
//     }
// }