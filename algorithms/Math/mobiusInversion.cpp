typedef long long ll;
const int MAXN = 1e5 + 5;

int cnt_sieve = 0;
vector<int> prime(MAXN);
vector<int> mobius(MAXN, 1);
vector<bool> isPrime(MAXN, true);

void sieve(){
	memset(isPrime, true, sizeof(isPrime));
	
	mobius[1] = 1; 
	
	for(ll i = 2; i < MAXN;i++){
            
		if(isPrime[i]){
			prime[++cnt_sieve] = i;
			mobius[i] = -1; 
		}
    
		for(ll j = 1; j <= cnt_sieve; j++){ 
			if(prime[j]*i >= MAXN) break;
 
		    	isPrime[prime[j]*i] = false;
        
			if(i % prime[j]) mobius[i*prime[j]] = -mobius[i];
			else{
				mobius [i*prime[j]] = 0;
				break;
			}
		}
	}
}
