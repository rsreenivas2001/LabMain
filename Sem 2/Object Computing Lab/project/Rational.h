class Rational
{
    private:
        int m;
        int n;
    public:
        Rational()
        {
            m=0;
            n=1;
        }
        Rational(int g,int h)
        {
            m=g;
            n=h;
        }
        bool check(Rational z);
        void disp();
};
bool Rational::check(Rational z)
{
    if(m==z.m&&n==z.n)
    return true;
    else
    return false;
}
void Rational::disp()
{
    cout<<m<<"/"<<n<<"\t";
}