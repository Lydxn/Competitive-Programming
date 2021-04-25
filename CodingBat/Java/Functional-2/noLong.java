public List<String> noLong(List<String> strings) {
  strings.removeIf(s -> s.length() >= 4);
  return strings;
}
