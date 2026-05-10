# Code Explanation – Binary Classification using Deep Neural Network on IMDB Dataset

Based on the uploaded Jupyter Notebook practical. :contentReference[oaicite:0]{index=0}

---

# 📌 Introduction

This program performs:

- Sentiment Analysis
- Binary Classification
- Deep Learning based NLP

using the IMDB Movie Review Dataset.

The model predicts whether a movie review is:

- Positive (1)
- Negative (0)

using a Deep Neural Network (DNN).

---

# 🧠 HPC Perspective

This practical belongs to:
- Deep Learning
- Artificial Intelligence
- High Performance Computing (HPC)

because:

- Large datasets are processed
- Matrix computations are performed
- Neural networks involve millions of calculations
- Training requires parallel processing

Deep learning frameworks internally use:
- GPU acceleration
- Parallel tensor operations
- Optimized computation graphs

---

# 📦 Step 1: Import Libraries

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import re

from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
```

---

# Explanation

## NumPy

```python
import numpy as np
```

Used for:
- Numerical computations
- Array operations
- Matrix processing

---

## Pandas

```python
import pandas as pd
```

Used for:
- Dataset handling
- CSV reading
- Data preprocessing

---

## Matplotlib

```python
import matplotlib.pyplot as plt
```

Used for:
- Accuracy graphs
- Visualization

---

## re

```python
import re
```

Used for:
- Text cleaning
- Removing symbols and HTML tags

---

## train_test_split

```python
from sklearn.model_selection import train_test_split
```

Used to divide dataset into:
- Training data
- Testing data

---

## TfidfVectorizer

```python
from sklearn.feature_extraction.text import TfidfVectorizer
```

Used to convert:
- Text → Numerical vectors

Neural networks cannot process raw text directly.

---

## Sequential Model

```python
from tensorflow.keras.models import Sequential
```

Used to create:
- Deep Neural Network architecture

---

## Dense Layer

```python
from tensorflow.keras.layers import Dense
```

Represents:
- Fully connected neural network layer

---

# HPC Concept

Deep learning libraries internally use:
- Parallel GPU computation
- Optimized tensor processing
- Matrix multiplication acceleration

---

# 📂 Step 2: Load Dataset

```python
df = pd.read_csv(
    "IMDB_Dataset.csv",
    encoding_errors='ignore',
    on_bad_lines='skip',
    engine='python'
)
```

---

# Explanation

Dataset loaded from:
```text
IMDB_Dataset.csv
```

---

# Parameters Used

| Parameter | Purpose |
|-----------|----------|
| encoding_errors='ignore' | Ignores encoding issues |
| on_bad_lines='skip' | Skips corrupted rows |
| engine='python' | Uses Python parser |

---

# Dataset Contains

| Column | Meaning |
|--------|----------|
| review | Movie review text |
| sentiment | Positive or Negative |

---

# Print Dataset

```python
print(df.head())
print(df.columns)
```

Displays:
- First few rows
- Column names

---

# 🧹 Step 3: Remove Null Values

```python
df = df.dropna()
```

---

# Why Important?

Null values can:
- Cause errors
- Reduce model accuracy
- Affect training

---

# Check Labels

```python
print(df['sentiment'].unique())
```

Shows:
```text
positive
negative
```

---

# 📛 Step 4: Rename Columns

```python
df.columns = ['review', 'sentiment']
```

---

# Purpose

Makes dataset:
- Cleaner
- Easier to access

---

# 🧽 Step 5: Text Cleaning

```python
def clean_text(text):

    text = str(text)
    text = text.lower()

    text = re.sub(r'<.*?>', '', text)

    text = re.sub(r'[^a-zA-Z ]', '', text)

    return text
```

---

# Explanation

## Convert to String

```python
text = str(text)
```

Ensures:
- All input is text format

---

## Lowercase Conversion

```python
text = text.lower()
```

Converts:
```text
GOOD → good
```

Improves consistency.

---

## Remove HTML Tags

```python
re.sub(r'<.*?>', '', text)
```

Removes:
```html
<br>
<div>
<p>
```

---

## Remove Symbols

```python
re.sub(r'[^a-zA-Z ]', '', text)
```

Removes:
- Numbers
- Special characters
- Punctuation

---

# Apply Cleaning

```python
df['review'] = df['review'].apply(clean_text)
```

Cleans every review.

---

# Why Text Cleaning Important?

Improves:
- Accuracy
- Vocabulary quality
- Feature extraction

---

# 🔄 Step 6: Convert Labels

```python
df['sentiment'] = df['sentiment'].map({
    'positive': 1,
    'negative': 0
})
```

---

# Explanation

Converts labels into numerical values.

| Sentiment | Value |
|-----------|-------|
| Positive | 1 |
| Negative | 0 |

---

# Why Conversion Needed?

Neural networks process:
- Numerical data only

---

# 📊 Step 7: TF-IDF Vectorization

```python
vectorizer = TfidfVectorizer(max_features=5000)
```

---

# What is TF-IDF?

TF-IDF means:

```text
Term Frequency – Inverse Document Frequency
```

It converts text into:
- Numerical vectors

---

# Why TF-IDF Used?

It identifies:
- Important words
- Frequently occurring meaningful terms

---

# Convert Reviews into Vectors

```python
X = vectorizer.fit_transform(df['review']).toarray()
```

---

# Explanation

Text reviews converted into:
```text
Numerical feature matrix
```

---

# Example

```text
"good movie"
```

becomes:

```text
[0.12, 0.45, 0.00, ...]
```

---

# Labels

```python
y = df['sentiment']
```

Stores:
- Output labels

---

# HPC Perspective

Vectorization performs:
- Large matrix operations
- Parallel numerical computation

---

# ✂️ Step 8: Train-Test Split

```python
X_train, X_test, y_train, y_test =
train_test_split(
    X, y,
    test_size=0.2,
    random_state=42
)
```

---

# Explanation

Dataset divided into:
- 80% Training Data
- 20% Testing Data

---

# Why Important?

Training data:
- Learns patterns

Testing data:
- Evaluates model performance

---

# 🧠 Step 9: Build Deep Neural Network

```python
model = Sequential()
```

Creates:
- Sequential neural network

---

# First Dense Layer

```python
model.add(Dense(
    128,
    activation='relu',
    input_shape=(X_train.shape[1],)
))
```

---

# Explanation

| Parameter | Meaning |
|-----------|----------|
| 128 | Number of neurons |
| relu | Activation function |
| input_shape | Input vector size |

---

# ReLU Activation

Formula:

:contentReference[oaicite:1]{index=1}

---

# Why ReLU Used?

Advantages:
- Fast training
- Prevents vanishing gradient
- Efficient computation

---

# Second Hidden Layer

```python
model.add(Dense(64, activation='relu'))
```

Additional feature learning layer.

---

# Output Layer

```python
model.add(Dense(1, activation='sigmoid'))
```

---

# Why 1 Neuron?

Binary classification:
- Positive
- Negative

---

# Sigmoid Activation

Formula:

:contentReference[oaicite:2]{index=2}

---

# Why Sigmoid Used?

Produces output between:
```text
0 and 1
```

Perfect for probability prediction.

---

# ⚙️ Step 10: Compile Model

```python
model.compile(
    optimizer='adam',
    loss='binary_crossentropy',
    metrics=['accuracy']
)
```

---

# Optimizer

```python
adam
```

Used for:
- Weight optimization
- Faster convergence

---

# Loss Function

```python
binary_crossentropy
```

Used for:
- Binary classification problems

Formula:

:contentReference[oaicite:3]{index=3}

---

# Accuracy Metric

Measures:
```text
Correct predictions percentage
```

---

# 🏋️ Step 11: Train Model

```python
history = model.fit(
    X_train,
    y_train,
    epochs=10,
    batch_size=32,
    validation_data=(X_test, y_test)
)
```

---

# Explanation

## Epochs

```python
epochs = 10
```

Means:
- Entire dataset processed 10 times

---

## Batch Size

```python
batch_size = 32
```

32 reviews processed together.

---

## Validation Data

Used to:
- Monitor performance
- Detect overfitting

---

# HPC Perspective

Training involves:
- Massive matrix multiplication
- Parallel tensor operations
- GPU acceleration

---

# 📈 Step 12: Plot Accuracy Graph

```python
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
```

---

# Purpose

Shows:
- Training accuracy
- Validation accuracy

---

# Why Graph Important?

Helps analyze:
- Learning progress
- Overfitting
- Underfitting

---

# 🎯 Step 13: Evaluate Model

```python
loss, accuracy =
model.evaluate(X_test, y_test)
```

---

# Explanation

Evaluates:
- Final loss
- Final accuracy

---

# Output Example

```text
Final Accuracy: 0.89
```

Means:
```text
89% prediction accuracy
```

---

# 🧠 Deep Learning Concepts Used

| Concept | Purpose |
|----------|----------|
| NLP | Text processing |
| Binary Classification | Positive/Negative prediction |
| TF-IDF | Text vectorization |
| DNN | Pattern learning |
| Dense Layer | Feature extraction |
| ReLU | Hidden layer activation |
| Sigmoid | Output probability |
| Adam Optimizer | Weight optimization |
| Binary Cross Entropy | Loss calculation |

---

# 🔥 HPC Concepts Used

| HPC Concept | Usage |
|-------------|-------|
| Parallel Processing | Tensor operations |
| GPU Acceleration | Faster training |
| Matrix Multiplication | Neural network computation |
| High Throughput Computing | Large dataset processing |
| Optimized Computation | TensorFlow backend |

---

# Sequential vs Parallel Deep Learning

| Sequential CPU | Parallel GPU |
|----------------|-------------|
| Slower | Faster |
| Limited computation | Massive parallel computation |
| Single core processing | Thousands of GPU cores |

---

# Important Viva Questions

# 1. What is Binary Classification?

Classification with two output classes.

---

# 2. Why IMDB Dataset Used?

For sentiment analysis and NLP tasks.

---

# 3. What is TF-IDF?

Technique used to convert text into numerical vectors.

---

# 4. Why text cleaning important?

Removes noise and improves model accuracy.

---

# 5. What is ReLU?

Activation function used in hidden layers.

---

# 6. What is Sigmoid?

Activation function producing probability output.

---

# 7. Why binary_crossentropy used?

Because output contains only two classes.

---

# 8. What is Adam Optimizer?

Optimization algorithm used to update weights.

---

# 9. What is Epoch?

One complete training cycle.

---

# 10. What is Batch Size?

Number of samples processed together.

---

# 11. What is Overfitting?

Model memorizes training data and performs poorly on new data.

---

# 12. Why GPUs used in deep learning?

Because deep learning requires massive parallel computation.

---

# 13. What is Deep Neural Network?

A neural network with multiple hidden layers.

---

# 14. Why vectorization required?

Neural networks process numerical input only.

---

# 15. What is Accuracy?

Percentage of correct predictions.

---

# Conclusion

This program successfully performs:

- Binary Classification
- Sentiment Analysis
- Deep Learning based NLP

using:
- IMDB Dataset
- TensorFlow
- Deep Neural Networks

The model learns movie review patterns and predicts:
- Positive sentiment
- Negative sentiment

This practical demonstrates:
- NLP preprocessing
- Neural network training
- Deep learning workflow
- HPC concepts in AI systems