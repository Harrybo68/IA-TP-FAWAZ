#include "../headers/dtw.h"

double DTW::compute(const vector<double>& x, const vector<double>& y) {
        int n = x.size();
        int m = y.size();

        // Initialisation de la matrice de coût avec des valeurs infinies
        vector<vector<double>> D(n + 1, vector<double>(m + 1, numeric_limits<double>::infinity()));
        D[0][0] = 0;

        // Remplissage de la matrice D
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                double cost = pow(x[i - 1] - y[j - 1], 2); // Coût au carré
                D[i][j] = cost + min(min(D[i - 1][j], D[i][j - 1]), D[i - 1][j - 1]);
            }
        }

        // La distance DTW est la racine carrée de la valeur finale dans D
        return sqrt(D[n][m]);
    }