public List<String> noYY(List<String> strings) {
  strings.replaceAll(s -> s + "y");
  strings.removeIf(s -> s.contains("yy"));
  return strings;
}
