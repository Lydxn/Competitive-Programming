public String[] mergeTwo(String[] a, String[] b, int n) {
  String[] arr = new String[n];
  for (int i = 0, aI = 0, bI = 0; i < n; i++) {
    if (a[aI].compareTo(b[bI]) < 0) {
      arr[i] = a[aI];
      aI++;
    } else if (a[aI].compareTo(b[bI]) > 0) {
      arr[i] = b[bI];
      bI++;
    } else {
      arr[i] = a[aI];
      aI++;
      bI++;
    }
  }
  return arr;
}
