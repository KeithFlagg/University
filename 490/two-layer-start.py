#!/usr/bin/python
#
#two-layer-start.py
#
#example of a two-layer 3*1 neural net

import sys
import numpy as np 
import matplotlib.pyplot as plt

#standard sigmoid
def nonlin(x, deriv = False):
    #establish return
    retval = -99999
    
    #detect if derivative is requested
    if(deriv):
        #An approximation to the derivative of the std. sigmoid
        retval = x*(1.0-x)
    else:
        #return sigmoid x
        retval = 1.0/(1.0 + np.exp(-x))
        
    return(retval)




#Create three-layer NN (3x4x1, static):
def three_layer_nn(X, y, iterations = 10000):
    #initialize data structures
    syn0 = 2 * np.random.random( (3, 4) ) - 1
    syn1 = 2 * np.random.random( (4,1) ) -1
    
    #loop through training data iterations
    for j in range(iterations):
        
        #Feed forward through NN (layers 0, 1, and 2)
        L0 = X
        L1 = nonlin(np.dot( L0, syn0 ) )
        L2 = nonlin(np.dot( L1, syn1 ) )
        
        #Compute error, compared with expected output
        L2_error = y - L2
        #create back-propagation correction
        L2_delta = L2_error * nonlin( L2, deriv = True )
        
        #Compute error for L1, compared with expectations
        L1_error = L2_delta.dot( syn1.T )
        
        #create the back-prop amounts for L1 based on the error:
        L1_delta = L1_error *nonlin( L1, deriv = True)
        
        #Modify the neural net
        syn1 += L1.T.dot(L2_delta)
        syn0 += L0.T.dot(L1_delta)

    #Return the important layers of the trained NN
    return( [syn0, syn1] )




# Create a two-layer (nx1) neural net, where X is the training data
# y is the desired output for the given data
# "iterations" is the number of training iteration
def two_layer_nn(X, y, iterations = 10):

    #initialize important info:
    
    #Get dimensions of the incoming data matrix:
    (m, n) = np.shape(X)
    #print(m, n)
    
    #initialize the weights of an (nx1) matrix with random
    #numbers from [-1, 1] (mean of 0) where n is num of inputs
    syn0 = 2 * np.random.random( (n, 1) ) - 1
    
    #print(syn0)
    #iterate through training dataset
    for iter in range(iterations):
            #forward propagation step:
            L0 = X
            L1 = nonlin( np.dot(L0, syn0) )
            
            #print(L1)
            
            #By how much did we miss the data (prediction)
            
            L1_error = y - L1
            
            #Multiply how much we missed by the slope of the nonlin
            #function at the values in L1
            
            L1_delta = L1_error * nonlin(L1, deriv=True)
            
            #print(L1_delta)
            
            #Update weights in synapse layer syn0
            #back propagation
            syn0 += np.dot( L0.T, L1_delta)
            
            #print(syn0)
            
    return( [ syn0 ] )




#Map given input vector v through the NN:
def predict( W, v ):
    for w in W:
        v = nonlin( np.dot(v,w) )
    return v
            
            

#Main function
def main(arglist):
        #print('Hello, Universe!')
        #Seed RNG to the same starting place
        np.random.seed(100)
        
        #Input dataset:
        X = np.array( [
            [0, 0, 1],
            [0, 1, 1],
            [1, 0, 1],
            [1, 1, 1]
                    ] )
        #print(x)
        #desired output
        y = np.array( [[0, 0, 1, 1]] ).T # "Easy"
        y2 = np.array( [[0, 1, 1, 0]] ).T # "Hard"
        
        #print(y)
        #print(y2)
        
        #Create nn for easy problem:
        W = two_layer_nn(X, y, iterations = 10000)
        
        #Create nn for hard problem:
        W2 = two_layer_nn(X, y2, iterations = 10000)
        
        #Create 3-layer nn for easy problem:
        W3 = three_layer_nn(X, y, iterations = 10000)
        
        #Create 3-layer nn for hard problem:
        W4 = three_layer_nn(X, y2, iterations = 10000)
        
        #print(W)
        
        #Easy
        print('\nThree-layer results for Easy example')
        print('-'*40)
        #Make a prediction on a known set of vals
        testInput = np.array( [[1,1,1]])
        expectedOutput = 1
        pred1 = predict( W3, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        
         #1 expected
        testInput = np.array( [[1,0,1]])
        expectedOutput = 1
        pred1 = predict( W3, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        
        #0 expected
        testInput = np.array( [[0,0,1]])
        expectedOutput = 0
        pred1 = predict( W3, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        
        #? Expected
        testInput = np.array( [[0,0,0]])
        #expectedOutput = 0
        pred1 = predict( W3, testInput)
        print('Test input: {}, expected output: ?'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        
        
        #Hard
        print('\nThree-layer results for Hard example')
        print('-'*40)
        #Make a prediction on a known set of vals
        testInput = np.array( [[0,0,1]])
        expectedOutput = 0
        pred1 = predict( W4, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        
        
        
        
        
        #print(W)
        print('\nTwo-layer results for Easy example')
        print('-'*40)
        
        #Make a prediction on a known set of vals
        testInput = np.array( [[1,1,1]])
        expectedOutput = 1
        pred1 = predict( W, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        #1 expected
        testInput = np.array( [[1,0,1]])
        expectedOutput = 1
        pred1 = predict( W, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        #0 expected
        testInput = np.array( [[0,0,1]])
        expectedOutput = 0
        pred1 = predict( W, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        #? Expected
        testInput = np.array( [[0,0,0]])
        #expectedOutput = 0
        pred1 = predict( W, testInput)
        print('Test input: {}, expected output: ?'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        
        print('\nTwo-layer results for Hard example')
        print('-'*40)
        
        #Make a prediction on a known set of vals
        testInput = np.array( [[0,0,1]])
        expectedOutput = 0
        pred1 = predict( W2, testInput)
        print('Test input: {}, expected output: {}'\
              .format(testInput, expectedOutput) )
        print('Predicted output: {}'.format(pred1))
        
        
        """
        #test sigmoid function
        testval = 0
        fn = nonlin
        fn2 = lambda x: 1.0/np.pi*np.arctan(x) + 0.5
        results = nonlin(testval)
        print('{} for x = {: 4.4f} is: {: 6.6f}'\
              .format(nonlin, testval, results))
        #Plot sigmoid function on [-10, 10]
        t = np.linspace(-10, 10, 101, endpoint = True)#domain
        s = np.array([nonlin(x) for x in t])
        r = np.array([fn2(x) for x in t])
        
        plt.plot(t, s, label = 'nonlin')
        plt.plot(t, r, label = 'arctan')
        plt.legend()
        plt.show()
        """
        
########################################   
#call main
#
if(__name__ == "__main__"):
    main(sys.argv[1:])
