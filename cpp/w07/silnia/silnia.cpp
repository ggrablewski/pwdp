int silnia(int n)
{
    return (n == 0) ? 1 : n * silnia(n - 1);
}

int main()
{
    return silnia(7);
}
