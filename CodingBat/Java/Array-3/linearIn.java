public boolean linearIn(int[] outer, int[] inner) {
  if (inner.length == 0) {
    return true;
  }
  
  int innerIndex = 0;
  for (int i = 0; i < outer.length; i++) {
    if (outer[i] == inner[innerIndex]) 
      innerIndex++;
    if (innerIndex == inner.length) 
      return true;
  }
  return false;
}
