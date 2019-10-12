
var set = [1,2,3,4]

var choicesByIndex = {'0':[1,2], '1':[2,3], '2':[1]}

var permGen = permutationGeneratorForSet(set, choicesByIndex);
var next = {};

while(!next.done){
    next = permGen.next();
    console.log(next.value);
}

function *permutationGeneratorForSet(set, choicesByIndex) {

    var choicesArrays = [];         // possible choices for each element for requested permutations
    var numOfEl = 0;
    var currentIndsOfChoices = [];  // indice array of current perm to compose
    var currentElInd = 0;           // indice of current elemet to add in perm list
    var newPerm = [];               // list for new permutation

	if (!validateParameters(set, choicesByIndex)) {
		return;
	}

	set = set.reduce((init, el, i) => set.indexOf(el) == i ? init.concat(el) : init, []); // be sure for it to be set
	numOfEl = set.length;

	init();
	let i = 0;
    while(currentIndsOfChoices[0] >= 0 && i++ < 100) {
        let nextPerm = getNextPerm();
        if (nextPerm) {
			if(nextPerm.filter(x=>x || x==0).length == nextPerm.length){	// if not exists any null value
				yield nextPerm ;
			}
        } else return;
    }

    function init() {
        for (let i = 0; i < numOfEl; i++) {
            choicesArrays.push(set);   // any item can place anywhere
        }

        currentIndsOfChoices[numOfEl - 1] = -1; // make last element as to be next

        choicesArrays = formatToChoicesArray(choicesByIndex, numOfEl, set) || choicesArrays;
        // Initialize the new permutation
        for (let i = 0; i < numOfEl; i++) {
            for (let j = 0; j < choicesArrays[i].length; j++) {

                if (newPerm.indexOf(choicesArrays[i][j]) < 0) {

                    newPerm[i] = choicesArrays[i][j];
                    currentIndsOfChoices[i] = j;
                    break;
                }
            }
        }

        // Remove last element so that algorithm resolve it
        currentIndsOfChoices[numOfEl - 1] = -1; // make last element as to be next
        newPerm[numOfEl - 1] = null;
    }

  
    next() {
        let nextPerm = this.getNextPerm();
        if (nextPerm) {
            while(nextPerm.filter(x=> x || x==0).length < nextPerm.length) {   // If nextPerm does not include empty item
                nextPerm = this.getNextPerm();
                if(!nextPerm || nextPerm.length == 0) {
                    return { done: true };
                }
             }

             return { done: false, value: nextPerm };

            }
        else { 
			return { done: true };
		}
    }

    function getNextPerm() {

        for (let i = numOfEl - 1; i >= 0 && i < numOfEl; i++) {
            let el = getAndSetPossibleNextElementForNewPerm(newPerm, choicesArrays[i], currentIndsOfChoices, i);
			
			while(el == 'EXISTINARRAY') {
                el = this.getAndSetPossibleNextElementForNewPerm(this.newPerm, this.choicesArrays[i], this.currentIndsOfChoices, i);
            }
			
            if (!el && el != 0) {   // if el is undefined or null
                while (!goBack(newPerm, choicesArrays, currentIndsOfChoices, --i)) {
                    if (i == 0) {
                        console.log('End of permutation!')
                        return;
                    }
                }
            } else {
                newPerm[i] = el;
            }
        }

        return newPerm.slice();
    }

    function goBack(newPerm, choicesArrays, currentIndsInChoices, elInd) {
        if (elInd >= 0 && elInd < numOfEl) {
            if (currentIndsInChoices[elInd] < choicesArrays[elInd].length - 1) {
                currentIndsInChoices[elInd + 1] = -1;	// Reset old
                newPerm[elInd + 1] = null;
                currentIndsInChoices[elInd]++;  // increment current
                if (newPerm.slice(0, elInd).indexOf(choicesArrays[elInd][currentIndsInChoices[elInd]]) < 0) {
                    newPerm[elInd] = choicesArrays[elInd][currentIndsInChoices[elInd]];
                    return true;
                } else {
                    return goBack(newPerm, choicesArrays, currentIndsInChoices, elInd);
                }
            } else {
                currentIndsInChoices[elInd + 1] = -1;	// Reset old
                newPerm[elInd + 1] = null;
                return false;
            }
        }

        return false;
    }

    function getAndSetPossibleNextElementForNewPerm(newPerm, choices, currentIndsInChoices, elInd) {
        if (elInd >= numOfEl) {
            currentIndsInChoices[elInd] = 0;	// will go back
            return null;
        }

        // If current element index does not exist then set it to zero
        if (!(currentIndsInChoices[elInd] >= 0)) {
            currentIndsInChoices[elInd] = 0;    //try starting from 0
        } else
            currentIndsInChoices[elInd]++;

        if (currentIndsInChoices[elInd] >= 0 && currentIndsInChoices[elInd] < choices.length) {
            if (newPerm.slice(0, elInd).indexOf(choices[currentIndsInChoices[elInd]]) >= 0) // If exist any where in new perm
            {
                return "EXISTINARRAY";
            }            newPerm[elInd] = choices[currentIndsInChoices[elInd]];
            return choices[currentIndsInChoices[elInd]]
        } else {
            currentIndsInChoices[elInd] = -1;
            newPerm[elInd] = null;
        }

        return undefined;
    }

    function validateParameters(elementSet, choicesByIndex) {
        if (!elementSet || elementSet.length == 0) {
            console.warn('Element list to permutate should be provided!');
            return false;
        }

        for (let i = 0; i < choicesByIndex.length; i++) {
            for (let j = 0; j < choicesByIndex[i]; j++) {
                if (elementSet.indexOf(choicesByIndex) < 0) {
                    console.warn('All choices should be in set!');
                    return false;
                }
            }

        }

        return true;
    }

    // Formats choices obj to array of choices
    function formatToChoicesArray(choicesByIndexObj, numOfElements, set) {
        if (!choicesByIndexObj) {
            return false;
        }

        var objectKeys = Object.keys(choicesByIndexObj);

        if (!objectKeys || !objectKeys.length) {
            return false;
        }

        var choicesArray = [];

        for (let i = 0; i < set.length; i++) {
            choicesArray[i] = choicesByIndexObj[i] || set;
        }

        return choicesArray;
    }

}

