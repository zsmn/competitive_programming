typedef long long ll;

const int m = 2;
const int MOD = 1e9 + 7;

class Matrix{
    public:
        ll mat[m][m] = {{0, 0}, {0, 0}};
        Matrix operator * (const Matrix &p){
            Matrix ans;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < m; j++)
                    for(int k = ans.mat[i][j] = 0; k < m; k++)
                        ans.mat[i][j] = (ans.mat[i][j] + 1LL * (mat[i][k]%MOD) * (p.mat[k][j]%MOD)) % MOD;
            return ans;
        }
};

Matrix fexp(Matrix a, ll b){
    Matrix ans;
    for(int i = 0; i < m; i++)
        ans.mat[i][i] = 1;

    while(b){
        if(b & 1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }

    return ans;
}
