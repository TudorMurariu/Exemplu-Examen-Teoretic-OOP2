#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Transformer {
    
public:
    virtual void transform(vector<int>& nrs)=0;
};

class Adder : public Transformer{
protected:
   int cat;
public:
    Adder(){}
    Adder(int cat1) : cat(cat1){}
    
    void transform(vector<int>& nrs) override
    {
        for(auto& x : nrs)
            x += cat;
    }
};

class Swapper : public Transformer{
    
    public:
    
    void transform(vector<int>& nrs) override
    {
        int n = nrs.size();
        for(int i=0;i<n-1;i+=2)
        {
            swap(nrs[i],nrs[i+1]);
        }
    }
};

class Nuller : public Adder {
public:
    Nuller(int cat1) 
    {
        cat = cat1;
    }
    
    void transform(vector<int>& nrs) override
    {
        Adder::transform(nrs);
        for(auto& x : nrs)
            if(x > 10)
                x = 0;
    }
};

class Composite : public Transformer{
    Transformer*t1 ,*t2;
public:
    Composite(Transformer* tn1,Transformer* tn2) : t1(tn1),t2(tn2){}
    
    void transform(vector<int>& nrs) override
    {
        t1->transform(nrs);
        t2->transform(nrs);
    }
};

class Numbers{
    Transformer*t1;
public:

  vector<int> nrs;
  Numbers(Transformer* tn1) : t1(tn1){}
  
  void addd(int x)
  {
      nrs.push_back(x);
  }
  
  static bool f(int x,int y)
  {
      return x > y;
  }
  
  void transform()
  {
      sort(nrs.begin(),nrs.end(),f);
      
      t1->transform(nrs);
  }
};

Numbers f()
{
    Nuller* nl = new Nuller(9);
    Adder* ad = new Adder(3);
    Swapper* swp = new Swapper;
    
    Composite* cmp1 = new Composite(ad,swp);
    Composite* cmp = new Composite(nl,cmp1);
    
    Numbers n(cmp);
    
    return n;
}

int main()
{
    Numbers n = f();
    n.addd(5);
    n.addd(1);
    n.addd(20);
    n.addd(4);
    n.addd(9);
    
    n.transform();
    for(auto& x : n.nrs)
        cout << x << " ";
        
    return 0;
}
