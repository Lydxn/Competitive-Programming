public String makeOutWord(String out, String word) {
  int mid = out.length() / 2;
  return out.substring(0, mid) + word + out.substring(mid);
}
