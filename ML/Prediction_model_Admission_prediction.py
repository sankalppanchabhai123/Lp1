import pandas as pd
import numpy as np
import seaborn as sb
import matplotlib.pyplot as plt

add= pd.read_csv("Admission_Predict.csv")
add.head()

add.columns

add["Chance of Admit "]=add["Chance of Admit "].apply(lambda x:1 if x >= 0.75 else 0)
X =add[['Serial No.', 'GRE Score', 'TOEFL Score', 'University Rating', 'SOP',
       'LOR ', 'CGPA', 'Research']]
Y =add[['Chance of Admit ']]
from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test =train_test_split(X, Y , test_size=0.2)
from sklearn.tree import DecisionTreeClassifier, plot_tree
model =DecisionTreeClassifier(criterion="entropy")
model.fit(X_train,Y_train)

y_predict = model.predict(X_test)
from sklearn.metrics import accuracy_score
accuracy_score(Y_test,y_predict)

from sklearn.metrics import confusion_matrix, classification_report
print(classification_report(Y_test,y_predict))

confusion_matrix(Y_test, y_predict)

from sklearn.tree import plot_tree
plot_tree(model, filled=True, feature_names=add.columns,max_depth=2,rounded=True)
