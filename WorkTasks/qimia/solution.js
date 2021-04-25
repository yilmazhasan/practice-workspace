// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)
    A.sort((x,y) => x > y ? 1 : -1);

    let indOfSmallestNonNegative = 0;

    for(;indOfSmallestNonNegative<A.length;indOfSmallestNonNegative++) {
        if(A[indOfSmallestNonNegative] > 0) {
            break;
        }
    }

    let smallestNonNegative = A[indOfSmallestNonNegative];

    if(smallestNonNegative > 1) {
        return 1;
    } else {

        // num is a next number in a sequence to be expected in list  
        for(let i = indOfSmallestNonNegative, num = 1; i < A.length; i++, num++) {
            // if is same with prev, do not increment num
            if(A[i-1] == A[i]) {
                num--;
                continue;
            }
            if(A[i] != num) {
                return num;
             }
         }
    }

    return A.length-indOfSmallestNonNegative+1;
}

console.log(solution([1,2,3,4,5,6,8,9,10,11,12,13]) == 7);
console.log(solution([1, 3, 6, 4, 1, 2]) == 5); //1,1,2,3,4,6 indOfSmallestNonNegative = 0, smallestNonNegative = 1
console.log(solution([1,2,3,4]) == 5);
console.log(solution([0,1,2,3,4]) == 5);
console.log(solution([0,-1,-2,1,2,3,4]) == 5);
console.log(solution([-1,1,2,2,4]) == 3); //indOfSmallestNonNegative = 1, smallestNonNegative = 1
console.log(solution([1,2,4]) == 3);
console.log(solution([-3,-2,-1,0,1,2,3]) == 4); // indOfSmalestNonNegative = 4, A.length = 7
