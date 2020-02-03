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
