li phi(li n) 
{ 
    li result = n;
  
    for(li p = 2; p * p <= n; ++p) 
    { 
          
        if (n % p == 0) 
        { 
            
            while (n % p == 0) 
                n /= p;

            result -= result / p; 
        } 
    } 
  
    if (n > 1) 
        result -= result / n;
    
    return result; 
} 