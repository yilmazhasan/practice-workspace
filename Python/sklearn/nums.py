%matplotlib inline
import matplotlib.pyplot as plt

from sklearn.datasets import load_digits

digits = load_digits()

dir(digits)

digits.data[0]

plt.gray()

for i in range(5):
    plt.matshow(digits.images[i])
plt.show()

digits.target[0] # -> 0


from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(digits.data, digits.target, test_size=0.2)
len(X_train)


from sklearn.linear_model import LogisticRegression
model = LogisticRegression()

model.fit(X_train, y_train)

model.score(X_test, y_test)

# model.predict()

plt.matshow(digits.images[67])

digits.target[67]

model.predict([digits.data[67]])


y_predicted = model.predict(X_test)
from sklearn.metrics import confusion_matrix

cm = confusion_matrix(y_test, y_predicted)

# visualize
import seaborn as sn
plt.figure(figsize=(10,7))
sn.heatmap(cm, annot=True)
plt.xlabel('Predicted')
plt.ylabel('Truth')

plt.show()




