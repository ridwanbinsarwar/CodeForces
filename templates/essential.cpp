/*********increase vector size**********/
int maxIndex ;
maxIndex = getMax(i, j);
if(v.size() <= maxIndex) {
while(v.size() <= maxIndex) {
v.push_back(vector<int>());
v[v.size() - 1].pb(0);
}
}
/*********increase vector size**********/

/**** Use of "sort()" for sorting on basis
    // of 2nd column */


bool sortcol( const vector<int>& v1,
              const vector<int>& v2 ) {
    return v1[1] < v2[1];
}

sort(vect.begin(), vect.end(),sortcol);

/**** asc sort vector of pair basis fd 2nd element******/
bool sortbysec(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second < b.second);
}
/**** Use of "sort()" for sorting on basis
    // of 2nd column */

/*****PRIME****************/
bool marked[M];
void sieve(int n) {
    for (int i = 3; i * i <= n; i++) {
        if (marked[i] == false) { // i is a prime
            for (int j = i * i; j <= n; j += i) {
                marked[j] = true;
            }
        }
    }
}
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return marked[n] == false;
}


/*********DIVISOR COUNT****/


vector<int> primes; // we'll preload primes once at the beginning
int countDivisor(int n) {
    int divisor = 1;
    for (int i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            int cnt = 1;
            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
    }
    return divisor;
}

/***digit**********/
int NumDigits(int x)
{
    x = abs(x);
    return (x < 10 ? 1 :
            (x < 100 ? 2 :
             (x < 1000 ? 3 :
              (x < 10000 ? 4 :
               (x < 100000 ? 5 :
                (x < 1000000 ? 6 :
                 (x < 10000000 ? 7 :
                  (x < 100000000 ? 8 :
                   (x < 1000000000 ? 9 :
                    10)))))))));
}

//is power of 2
bool isPowerOfTwo(ll int n)
{
    if(n==0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
/// 2^3
(2 << (3ULL - 1))

//fast_power
long long int fast_power(long long int base, long long int power) {
    long long int result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}


Set bit: num = num | (1 << i)

Clear bit : num = num & ~(1 << i)

Toggle bit: num = num ^ (1 << i)

Get bit: num = (num >> i) & 1