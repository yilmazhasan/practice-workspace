import numpy as np # linear algebra

def gradient_descent(X, y):
    m_curr = b_curr = 0
    
    iterations = 10
    n = len(X)
    
    learning_rate = 0.0001

    
    # d/db -> derivative according to b
    # d/dm = 2/n * E(i = 1 -> n) -xi*(yi-(m*xi+b))
    # d/db = 2/n * E(i = 1 -> n) -*(yi-(m*xi+b))
    # m = m - learning_rate * d/dm
    # b = b - learning_rate * d/db
    # mss = (1/n) * E (i=1 -> n) ((yi - y_predicted)^2)
    
    for i in range(iterations):
        y_predicted = m_curr * X + b_curr
        cost = (1/n) * sum([val**2 for val in (y-y_predicted)])
        m_deriv = -(2/n) * sum(X*(y-y_predicted))
        b_deriv = -(2/n) * sum(y-y_predicted)
        m_curr = m_curr - learning_rate * m_deriv
        b_curr = b_curr - learning_rate * b_deriv
    
        print("m {}  b {}, cost {} iteration {} ".format(m_curr, b_curr, cost, i))
    
    
X = np.array([1,2,3,4,5])
y = np.array([5,7,9,11,13])

gradient_descent(X,y)
