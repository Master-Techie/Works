import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.svm import LinearSVC
from sklearn.metrics import accuracy_score, classification_report

# 1. Load Dataset (Example CSV format: 'lyrics', 'genre')
# Replace 'dataset.csv' with your dataset file path
data = pd.read_csv('dataset.csv')

# 2. Preprocessing
# Drop NaN values and reset the index
data = data.dropna().reset_index(drop=True)

# Extract features (lyrics) and labels (genre)
X = data['lyrics']
y = data['genre']

# 3. Split Data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 4. Text Vectorization
# Convert lyrics to numerical features using TfidfVectorizer
tfidf = TfidfVectorizer(stop_words='english', max_features=5000)
X_train_tfidf = tfidf.fit_transform(X_train)
X_test_tfidf = tfidf.transform(X_test)

# 5. Model Training
# Using a Linear Support Vector Classifier (LinearSVC)
model = LinearSVC()
model.fit(X_train_tfidf, y_train)

# 6. Model Evaluation
# Predict genres for the test set
y_pred = model.predict(X_test_tfidf)

# Calculate accuracy and print classification report
accuracy = accuracy_score(y_test, y_pred)
print(f'Accuracy: {accuracy:.2f}')
print('\nClassification Report:\n')
print(classification_report(y_test, y_pred))

# 7. Save the Model and Vectorizer
import joblib

# Save the trained model
joblib.dump(model, 'music_genre_classifier_model.pkl')

# Save the TfidfVectorizer
joblib.dump(tfidf, 'tfidf_vectorizer.pkl')

# 8. Loading and Using the Model
# Example: Load and predict
loaded_model = joblib.load('music_genre_classifier_model.pkl')
loaded_tfidf = joblib.load('tfidf_vectorizer.pkl')
sample_lyrics = ["sample lyrics here"]
sample_features = loaded_tfidf.transform(sample_lyrics)
predicted_genre = loaded_model.predict(sample_features)
print(predicted_genre)
