public boolean cigarParty(int cigars, boolean isWeekend) {
  return (!isWeekend && (cigars >= 40 && cigars <= 60)) || (isWeekend && cigars > 39) ? true : false;
}
