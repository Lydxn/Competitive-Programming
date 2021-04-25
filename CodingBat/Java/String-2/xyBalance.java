public boolean xyBalance(String str) {
	for (int i = str.length() - 1, ch; i >= 0; i--) {
		ch = str.charAt(i);
		if (ch == 'x')
			return false;
		else if (ch == 'y')
			return true;
	}
	return true; 
}
