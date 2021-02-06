
bool isReverse(string str1, string str2) {
	int lastIndex = str.size()-1;
	for(int i = 0; i < sizeToLook; i++) {
		if(str1[i] != str2[lastIndex-i]) {
			return false;
		}

		return true;
	}
}

bool isPalindrome (string str) {
	int indexFromLast = str.size()-1;

	for(int i = 0; i < indexFromLast; i++, indexFromLast--) {
		if(str[i] != str[indexFromLast]) {
			return false;
		}
	}
	return true;
}

