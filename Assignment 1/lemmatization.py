from nltk.stem import WordNetLemmatizer
import nltk
nltk.download('wordnet')


lematizer = WordNetLemmatizer()

sentence = "Hello I am Yash.I am a Third Year Student in CSE(AI) Department.Recently i finished my fifth semester and we have holidays for near about 1 months around 40 days.This time i decided not to spend more time at home as i have to study and be prepared for placement interviews also i am lacking a lot in prokects and all"

breaks = sentence.split()
stem = [lematizer.lemmatize(breakk) for breakk in breaks]
print(stem)