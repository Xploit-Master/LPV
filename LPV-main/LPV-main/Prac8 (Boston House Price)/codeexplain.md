# Code Explanation – Boston House Price Prediction using Deep Neural Network

Based on the uploaded Jupyter Notebook practical file. :contentReference[oaicite:0]{index=0}

---

# 📌 Introduction

This program implements:

- Linear Regression using Neural Network
- Boston House Price Prediction
- Deep Learning using TensorFlow and Keras

The program trains a Deep Neural Network (DNN) model to predict house prices using the Boston Housing Dataset.

This practical belongs to:
- Deep Learning
- Machine Learning
- Artificial Intelligence

---

# 📖 HPC / Deep Learning Perspective

In High Performance Computing (HPC) and Deep Learning:

- Large datasets require fast computation
- Neural networks involve millions of mathematical operations
- Libraries like TensorFlow use:
  - Parallel computation
  - GPU acceleration
  - Optimized matrix operations

Deep learning models are computationally intensive and benefit from parallel processing.

---

# Step 1: Import Libraries

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
```

---

# Explanation

This section imports all required libraries.

| Library | Purpose |
|----------|----------|
| NumPy | Numerical computations |
| Pandas | Data handling |
| Matplotlib | Graph plotting |
| train_test_split | Splits dataset |
| StandardScaler | Feature normalization |
| TensorFlow | Deep learning framework |
| Sequential | Neural network model |
| Dense | Fully connected layers |

---

# Why TensorFlow is Used?

TensorFlow is a Deep Learning framework developed by Google.

Advantages:
- Fast computation
- GPU support
- Parallel execution
- Efficient matrix operations
- Automatic optimization

---

# Why Keras is Used?

Keras is a high-level API of TensorFlow.

Used because:
- Easy neural network creation
- Simple syntax
- Beginner friendly
- Fast model building

---

# Step 2: Load Dataset

```python
df = pd.read_csv("1_boston_housing.csv")
```

---

# Explanation

Reads Boston Housing dataset from CSV file.

Dataset contains:
- House features
- House prices

---

# Remove Quotes from Column Names

```python
df.columns = df.columns.str.replace('"', '')
```

---

# Why This is Needed?

Sometimes CSV column names contain quotation marks.

This line:
- Removes unnecessary quotes
- Makes column names clean

---

# Display First 5 Rows

```python
df.head()
```

---

# Purpose

Displays:
- First 5 dataset rows
- Dataset structure
- Feature names

---

# Step 3: Split Features and Target

```python
X = df.drop("MEDV", axis=1)
y = df["MEDV"]
```

---

# Explanation

Dataset divided into:

| Variable | Purpose |
|----------|----------|
| X | Input features |
| y | Target value |

---

# What is MEDV?

MEDV =
Median value of owner-occupied homes.

This is the output variable.

---

# Why Features and Target are Separated?

Machine learning models require:

- Inputs → Features
- Outputs → Labels/Target

---

# Shape of Dataset

```python
print(X.shape, y.shape)
```

---

# Purpose

Displays:
- Number of rows
- Number of columns

Example:
```text
(506, 13)
```

Meaning:
- 506 records
- 13 features

---

# Step 4: Train-Test Split

```python
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)
```

---

# Explanation

Dataset split into:

| Dataset | Purpose |
|----------|----------|
| Training Data | Train model |
| Testing Data | Evaluate model |

---

# test_size = 0.2

Means:
- 80% data → Training
- 20% data → Testing

---

# random_state = 42

Used for:
- Reproducibility
- Same random split every run

---

# Why Train-Test Split is Important?

Without testing:
- Cannot measure accuracy
- Cannot detect overfitting

---

# Step 5: Feature Scaling

```python
scaler = StandardScaler()

X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
```

---

# What is Feature Scaling?

Different features have different ranges.

Example:
- TAX → large values
- RM → small values

Scaling normalizes data.

---

# Standardization Formula

:contentReference[oaicite:1]{index=1}

Where:

| Symbol | Meaning |
|--------|----------|
| μ | Mean |
| σ | Standard deviation |

---

# Why Scaling is Important?

Scaling:
- Improves training speed
- Improves accuracy
- Prevents dominance of large values

---

# Step 6: Build Deep Neural Network

```python
model = Sequential()
```

---

# Explanation

Creates Sequential Neural Network model.

Sequential means:
- Layers added one after another

---

# Add Dense Layer

```python
model.add(Dense(1,
input_shape=(X_train.shape[1],),
activation='linear'))
```

---

# Explanation

Creates:
- 1 output neuron
- Linear activation function

---

# What is Dense Layer?

Dense layer means:
- Every neuron connected to all neurons in previous layer

---

# input_shape

```python
input_shape=(13,)
```

13 input features are passed into model.

---

# Why activation='linear'?

Linear activation used for:
- Regression problems
- Continuous numerical prediction

Like:
- House prices
- Temperature
- Sales prediction

---

# Step 7: Compile Model

```python
model.compile(
    optimizer='adam',
    loss='mse',
    metrics=['mae']
)
```

---

# Explanation

Configures model training process.

---

# Optimizer = Adam

Adam optimizer:
- Updates weights efficiently
- Faster convergence
- Most popular optimizer

---

# Loss Function = MSE

MSE = Mean Squared Error

Formula:

:contentReference[oaicite:2]{index=2}

---

# Why MSE Used?

Measures prediction error.

Lower MSE:
- Better predictions

---

# Metric = MAE

MAE = Mean Absolute Error

Formula:

:contentReference[oaicite:3]{index=3}

---

# Why MAE Used?

Shows average prediction error.

Easy to interpret.

---

# Step 8: Model Summary

```python
model.summary()
```

---

# Purpose

Displays:
- Number of layers
- Number of neurons
- Trainable parameters

---

# Step 9: Train Model

```python
history = model.fit(
    X_train,
    y_train,
    epochs=100,
    batch_size=16,
    validation_split=0.2,
    verbose=1
)
```

---

# Explanation

Trains neural network.

---

# epochs = 100

Model sees training data:
- 100 times

---

# batch_size = 16

16 samples processed together.

---

# validation_split = 0.2

20% training data used for validation.

---

# verbose = 1

Displays training progress.

---

# What Happens During Training?

1. Forward propagation
2. Prediction generation
3. Error calculation
4. Backpropagation
5. Weight update

Repeated for many epochs.

---

# Forward Propagation

Input passes through network.

Prediction generated.

---

# Backpropagation

Error used to update weights.

---

# Gradient Descent

Optimization process minimizing loss.

---

# Step 10: Evaluate Model

```python
loss, mae = model.evaluate(X_test, y_test)
```

---

# Purpose

Evaluates performance on unseen data.

---

# Output

```python
print("Test Loss (MSE):", loss)
print("Test MAE:", mae)
```

---

# Meaning

| Metric | Meaning |
|--------|----------|
| Loss | Prediction error |
| MAE | Average absolute error |

Lower values indicate:
- Better model performance

---

# Step 11: Predictions

```python
y_pred = model.predict(X_test)
```

---

# Purpose

Predicts house prices using trained model.

---

# Compare Actual vs Predicted

```python
for i in range(5):
    print(f"Actual: {y_test.iloc[i]:.2f} |
    Predicted: {y_pred[i][0]:.2f}")
```

---

# Explanation

Compares:
- Actual house price
- Predicted house price

Used to verify model accuracy.

---

# Step 12: Plot Training Graphs

```python
plt.plot(history.history['loss'],
label='Training Loss')

plt.plot(history.history['val_loss'],
label='Validation Loss')
```

---

# Purpose

Visualizes:
- Training loss
- Validation loss

---

# Why Graphs are Important?

Graphs help detect:
- Overfitting
- Underfitting
- Learning quality

---

# Training Loss

Error on training dataset.

---

# Validation Loss

Error on validation dataset.

---

# Good Model Behavior

Training and validation loss should:
- Decrease gradually
- Remain close together

---

# Concepts Used in This Practical

| Concept | Purpose |
|----------|----------|
| Deep Learning | Intelligent prediction |
| Neural Network | Learning patterns |
| Regression | Predict numerical values |
| Dense Layer | Fully connected computation |
| Standardization | Feature normalization |
| Backpropagation | Weight update |
| Gradient Descent | Loss minimization |
| TensorFlow | Deep learning framework |
| Keras | Neural network API |

---

# Deep Learning Workflow Used

```text
Dataset
   ↓
Preprocessing
   ↓
Train-Test Split
   ↓
Feature Scaling
   ↓
Model Building
   ↓
Model Training
   ↓
Evaluation
   ↓
Prediction
```

---

# HPC Perspective of This Practical

Deep Learning requires:
- Large matrix operations
- High computation power
- Parallel execution

TensorFlow internally uses:
- CPU parallelism
- GPU acceleration
- Optimized tensor operations

This makes Deep Learning suitable for:
- High Performance Computing (HPC)

---

# Why GPU Acceleration is Important?

Neural networks involve:
- Millions of calculations
- Matrix multiplications
- Parallel mathematical operations

GPUs execute these operations faster than CPUs.

---

# Sequential vs Parallel Processing

| Sequential | Parallel |
|------------|-----------|
| One operation at a time | Multiple operations simultaneously |
| Slower | Faster |
| CPU-focused | GPU-focused |
| Limited scalability | High scalability |

---

# Important Viva Questions

## 1. What is Deep Learning?

Subset of machine learning using neural networks.

---

## 2. What is Neural Network?

A computational model inspired by the human brain.

---

## 3. What is Boston Housing Dataset?

A regression dataset for house price prediction.

---

## 4. Why feature scaling is required?

To normalize feature values for better learning.

---

## 5. What is Dense layer?

A fully connected neural network layer.

---

## 6. What is activation function?

Function introducing non-linearity into network.

---

## 7. Why linear activation used here?

Because house price prediction is regression problem.

---

## 8. What is optimizer?

Algorithm that updates model weights.

---

## 9. What is Adam optimizer?

Efficient optimization algorithm for deep learning.

---

## 10. What is MSE?

Mean Squared Error used as loss function.

---

## 11. What is MAE?

Mean Absolute Error measuring average error.

---

## 12. What is epoch?

One complete pass through training dataset.

---

## 13. What is batch size?

Number of samples processed together.

---

## 14. What is overfitting?

Model memorizes training data and performs poorly on new data.

---

## 15. Why TensorFlow is used?

For efficient deep learning computation and GPU acceleration.

---

# Conclusion

This practical successfully implemented:

- Boston House Price Prediction
- Linear Regression using Deep Neural Network
- Model training and evaluation using TensorFlow and Keras

The program demonstrated:
- Data preprocessing
- Feature scaling
- Neural network training
- Prediction generation
- Performance evaluation

This practical provides strong understanding of:
- Deep Learning
- Regression
- Neural Networks
- Machine Learning workflow
- HPC concepts in AI