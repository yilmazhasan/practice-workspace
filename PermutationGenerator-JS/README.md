## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Usage](#usage)

## General info
This is a permutation generator of a set (distinct elements)
	
## Technologies
Created with:
* Javascript
	
## Usage
*To use, copy the generator function and give appropriate parameters.
*To indicate choices parameter, it is a constraint for any index of a requested permutation.
*File includes a test function for simple usage.
*next function returns an object such as {value: any[], done:boolean}

```javascript

    var set = [1,2,3,4]
    var choicesByIndex = {'0':[1,2], '1':[2,3], '2':[1]}

    var permGen = permutationGeneratorForSet(set, choicesByIndex);
    permGen.next();

```