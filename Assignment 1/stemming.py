from nltk.stem import PorterStemmer

stemmer = PorterStemmer()

words = ['running','runner','ran','runs','easily','fairness']
sentence = "Hello I am Yash.I am a Third Year Student in CSE(AI) Department.Recently i finished my fifth semester and we have holidays for near about 1 months around 40 days.This time i decided not to spend more time at home as i have to study and be prepared for placement interviews also i am lacking a lot in prokects and all"

breaks = sentence.split()

stems = [stemmer.stem(word) for word in words ]
stem = [stemmer.stem(breakk) for breakk in breaks]

print(stem)