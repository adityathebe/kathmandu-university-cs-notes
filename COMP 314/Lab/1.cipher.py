def encode(phrase, shift_value):
  encoded_phrase = ''
  for char in phrase:
    if char.isalnum():
      ascii_value = ord(char)
      new_ascii_value = 0

      # range (0, 9) => (48, 57)
      if (ascii_value <= 57):
        new_ascii_value = (ascii_value + shift_value) % 57
        if (new_ascii_value != (ascii_value + shift_value)):
          new_ascii_value += 47

      # range (A, Z) => (65, 90)
      elif ascii_value <= 90:
        new_ascii_value = (ascii_value + shift_value) % 90
        if (new_ascii_value != (ascii_value + shift_value)):
          new_ascii_value += 64

      # range (A, Z) => (97, 122)
      else:
        new_ascii_value = (ascii_value + shift_value) % 122
        if (new_ascii_value != (ascii_value + shift_value)):
          new_ascii_value += 96

      # Conact alphnum value
      encoded_phrase += chr(new_ascii_value)

    else:
      encoded_phrase += char

  return encoded_phrase


if __name__ == "__main__":
  user_phrase = input('Enter sentence to encrypt: ')
  shift_value = int(input('Enter shift value: '))
  encoded_phrase = encode(user_phrase, shift_value)
  print('The encoded phrase is : {}'.format(encoded_phrase))
