public boolean stringE(String str) {
  long e = str.chars().filter(ch -> ch == 'e').count();
  return e >= 1 && e <= 3;
}
