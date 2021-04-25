public String fizzString(String str) {
  if (str.startsWith("f") == true && str.endsWith("b") == true) 
    return "FizzBuzz";
  else if (str.startsWith("f")) 
    return "Fizz";
  else if (str.endsWith("b")) 
    return "Buzz";
  else
    return str;
}
