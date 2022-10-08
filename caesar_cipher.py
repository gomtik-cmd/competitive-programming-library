def encrypt(string, shift):
 
  encOutput = ''
  for charOrdinal in string:
    if charOrdinal == ' ':
      encOutput = encOutput + charOrdinal
    elif  charOrdinal.isupper():
      encOutput = encOutput + chr((ord(charOrdinal) + shift - 65) % 26 + 65)
    else:
      encOutput = encOutput + chr((ord(charOrdinal) + shift - 97) % 26 + 97)
  
  return encOutput
 
inputstr = input("enter string: ")
s = int(input("enter shift number: "))
print("original string: ", inputstr)
print("after encryption: ", encrypt(inputstr, s))
