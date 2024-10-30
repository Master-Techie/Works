import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import LabelEncoder
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
import matplotlib.pyplot as plt

dataset = pd.read_csv('Breast_Cancer(1).csv')

label_encoders = {}
for column in dataset.select_dtypes(include=['object']).columns:
    if column != 'Status':
        le = LabelEncoder()
        dataset[column] = le.fit_transform(dataset[column])
        label_encoders[column] = le

target_le = LabelEncoder()
dataset['Status'] = target_le.fit_transform(dataset['Status'])

X = dataset.drop(columns=['Status'])
y = dataset['Status']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Gini-based Decision Tree
gini_tree = DecisionTreeClassifier(criterion='gini', random_state=42)
gini_tree.fit(X_train, y_train)
y_predicted_gini = gini_tree.predict(X_test)
gini_accuracy = accuracy_score(y_test, y_predicted_gini)

# Entropy-based Decision Tree
entropy_tree = DecisionTreeClassifier(criterion='entropy', random_state=42)
entropy_tree.fit(X_train, y_train)
y_predicted_entropy = entropy_tree.predict(X_test)
entropy_accuracy = accuracy_score(y_test, y_predicted_entropy)

# Random Forest
random_forest = RandomForestClassifier(n_estimators=100, random_state=42)
random_forest.fit(X_train, y_train)
y_predicted_rf = random_forest.predict(X_test)
rf_accuracy = accuracy_score(y_test, y_predicted_rf)

print(f"Gini Decision Tree Accuracy: {gini_accuracy}")
print(f"Entropy Decision Tree Accuracy: {entropy_accuracy}")
print(f"Random Forest Accuracy: {rf_accuracy}")

epochs = range(1, 21)

gini_accuracy_scores = []
for epoch in epochs:
    gini_tree.fit(X_train, y_train)
    y_pred_epoch_gini = gini_tree.predict(X_test)
    gini_accuracy_scores.append(accuracy_score(y_test, y_pred_epoch_gini))

plt.figure(figsize=(10, 5))
plt.plot(epochs, gini_accuracy_scores, label='Gini Validation Accuracy', color='green')
plt.xlabel('Epochs')
plt.ylabel('Accuracy')
plt.title('Gini Decision Tree Accuracy over Epochs')
plt.legend()
plt.show()

entropy_accuracy_scores = []
for epoch in epochs:
    entropy_tree.fit(X_train, y_train)
    y_pred_epoch_entropy = entropy_tree.predict(X_test)
    entropy_accuracy_scores.append(accuracy_score(y_test, y_pred_epoch_entropy))

plt.figure(figsize=(10, 5))
plt.plot(epochs, entropy_accuracy_scores, label='Entropy Validation Accuracy', color='blue')
plt.xlabel('Epochs')
plt.ylabel('Accuracy')
plt.title('Entropy Decision Tree Accuracy over Epochs')
plt.legend()
plt.show()

rf_accuracy_scores = []
for epoch in epochs:
    random_forest.fit(X_train, y_train)
    y_pred_epoch_rf = random_forest.predict(X_test)
    rf_accuracy_scores.append(accuracy_score(y_test, y_pred_epoch_rf))

plt.figure(figsize=(10, 5))
plt.plot(epochs, rf_accuracy_scores, label='Random Forest Validation Accuracy', color='red')
plt.xlabel('Epochs')
plt.ylabel('Accuracy')
plt.title('Random Forest Accuracy over Epochs')
plt.legend()
plt.show()