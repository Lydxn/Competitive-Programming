public Map<String, String> mapAB4(Map<String, String> map) {
  if (map.containsKey("a") && map.containsKey("b"))
    if (map.get("a").length() == map.get("b").length()) {
      map.put("a", "");
      map.put("b", "");
    } else
      map.put("c", map.get(map.get("a").length() > map.get("b").length() ? "a" : "b"));
  return map;
}
