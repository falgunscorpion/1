import nltk
from nltk.tokenize import word_tokenize
from nltk import pos_tag


nltk.download('punkt')
nltk.download('punkt_tab')
nltk.download('averaged_perceptron_tagger_eng')

text = """Hello I am Yash. I am a Third Year Student in CSE(AI) Department.
Recently I finished my fifth semester and we have holidays for about 40 days.
This time I decided not to spend more time at home as I have to study and
prepare for placement interviews. Also I am lacking a lot in projects."""

tokens = word_tokenize(text)
tagged_words = pos_tag(tokens)

print("POS Tags using NLTK:")
print(tagged_words)
