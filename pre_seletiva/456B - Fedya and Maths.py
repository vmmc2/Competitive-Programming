def main():
    n = int(input())
    real_n = n%4
    a1 = pow(1, real_n)
    a2 = pow(2, real_n)
    a3 = pow(3, real_n)
    a4 = pow(4, real_n)
    answer = (a1 + a2 + a3 + a4)%5
    print(answer)
    
main()
