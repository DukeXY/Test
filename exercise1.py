'''
Project Euler - Exercise 1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
'''

def main():
    answer = 0
    
    natural_nums_below_thousand = xrange(1, 1000)
    for num in natural_nums_below_thousand:
        if (num % 3 == 0) or (num % 5 == 0):
            answer += num
    
    print answer
    
if __name__ == '__main__':
    main()