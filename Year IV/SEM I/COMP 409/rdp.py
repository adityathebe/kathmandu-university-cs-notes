# Grammar
# S -> cAd
# A -> ab | a

def S(inp, sPtr = 0):
  global wPtr
  prod = G["S"][sPtr]
  print("** S -> {}".format(prod))
  for x in prod:
    print("Testing {}".format(x))
    if x in V:
      if x == "A":
        A(inp)
      elif x == "S":
        S(inp)
      else:
        raise ValueError("Unhandled Non Terminal")
    elif x in T:
      if inp[wPtr] == x:
        print("Matched !")
        wPtr += 1
      else:
        print("Did not match !. Using next production rule")
        sPtr += 1
        wPtr -= 1
        if sPtr == len(G["S"]):
          raise ValueError('String Rejected.')
        else:
          S(inp, sPtr)
    else:
      raise ValueError('Invalid symbol in input string.')

def A(inp, aPtr = 0):
  global wPtr
  prod = G["A"][aPtr]
  print("** A -> {}".format(prod))
  for x in prod:
    print("Testing {}".format(x))
    if x in V:
      if x == "A":
        A(inp)
      elif x == "S":
        S(inp)
      else:
        raise ValueError("Unhandled Non Terminal")
    elif x in T:
      if inp[wPtr] == x:
        print("Matched !")
        wPtr += 1
      else:
        print("Did not match !. Using next production rule")
        aPtr += 1
        wPtr -= 1
        if aPtr == len(G["A"]):
          raise ValueError('String Rejected.')
        else:
          A(inp, aPtr)
    else:
      raise ValueError('Invalid symbol in input string.')

if __name__ == "__main__":
  # Grammar
  G = {
    "S" :["cAd"],
    "A" : ["ab", "a"]
  }

  V = ["S", "A"]
  T = ["c", "a", "b", "d"]

  w = "cad"
  wPtr = 0
  
  # Start Parsing
  S(w)
  print("Accepted")