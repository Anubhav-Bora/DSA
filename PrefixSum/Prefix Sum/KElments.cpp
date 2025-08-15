

class ProductOfNumbers {
    vector<int> prefixProd;
public:
    ProductOfNumbers() {
        prefixProd = {1};  
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProd = {1};
        } else {
            prefixProd.push_back(prefixProd.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProd.size();
        if (k >= n) {
            return 0;
        }
        return prefixProd.back() / prefixProd[n - 1 - k];
    }
};
