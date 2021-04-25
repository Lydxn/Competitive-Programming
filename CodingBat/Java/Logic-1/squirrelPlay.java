public boolean squirrelPlay(int temp, boolean isSummer) {
  return temp >= 60 && ((temp <= 90 && !isSummer) || (temp <= 100 && isSummer)) ? true : false;
}
