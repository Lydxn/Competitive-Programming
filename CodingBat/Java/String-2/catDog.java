public boolean catDog(String str) {
  int dog = 0;
  int cat = 0;
  for (int i = 0; i < str.length() - 2; i++) {
    if (str.substring(i, i + 3).equals("cat"))  
      cat++;
    if (str.substring(i, i + 3).equals("dog")) 
      dog++;
  }
  return cat == dog;
}
