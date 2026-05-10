# Code Explanation – Fashion MNIST Classification using CNN

This program performs:

- Image Classification
- Multiclass Classification
- Deep Learning using CNN

on the Fashion MNIST Dataset using TensorFlow and Keras.

The model classifies fashion clothing images into categories such as:
- T-shirt
- Trouser
- Dress
- Bag
- Sneaker
- Sandal
- Ankle Boot

---

# 📌 Introduction

This practical uses:
- Convolutional Neural Network (CNN)
- TensorFlow
- Keras
- Deep Learning

to classify clothing images.

This is a:
```text
Multiclass Classification Problem
```

because:
- There are 10 output classes.

---

# 🧠 HPC Perspective

This practical belongs to:
- Deep Learning
- Computer Vision
- High Performance Computing (HPC)

because training CNN models involves:
- Large matrix operations
- Parallel tensor processing
- GPU acceleration
- Massive computations

TensorFlow internally uses:
- CUDA
- GPU cores
- Parallel computation

---

# 📦 Cell 1 — Import Libraries

```python
import tensorflow as tf
import matplotlib.pyplot as plt
from tensorflow import keras
import numpy as np
```

---

# TensorFlow

```python
import tensorflow as tf
```

TensorFlow is a Deep Learning framework.

Used for:
- Neural network creation
- GPU acceleration
- Tensor operations

---

# Matplotlib

```python
import matplotlib.pyplot as plt
```

Used for:
- Image display
- Accuracy graph plotting

---

# Keras

```python
from tensorflow import keras
```

Keras is TensorFlow’s high-level API.

Used for:
- Building CNN models easily

---

# NumPy

```python
import numpy as np
```

Used for:
- Array operations
- Numerical computations

---

# 📂 Cell 2 — Load Fashion MNIST Dataset

```python
(x_train, y_train), (x_test, y_test) =
keras.datasets.fashion_mnist.load_data()
```

---

# Explanation

Dataset automatically downloaded from TensorFlow.

Contains:
- Training images
- Testing images

---

# Dataset Size

| Dataset | Images |
|---------|---------|
| Training | 60,000 |
| Testing | 10,000 |

---

# Image Size

Each image:
```text
28 × 28 pixels
```

---

# 🎽 Cell 3 — Fashion Labels

```python
# 0 = T-shirt/top
# 1 = Trouser
# 2 = Pullover
# 3 = Dress
# 4 = Coat
# 5 = Sandal
# 6 = Shirt
# 7 = Sneaker
# 8 = Bag
# 9 = Ankle Boot
```

---

# Purpose

Defines mapping between:
- Numbers
- Fashion categories

---

# 🖼️ Cell 4 — Display Images

```python
plt.imshow(x_train[0], cmap='gray')
```

---

# Explanation

Displays sample training images.

---

# cmap='gray'

Shows image in grayscale format.

---

# Why Visualize Images?

Helps:
- Understand dataset
- Verify image quality

---

# 🧹 Cell 5 — Normalize Dataset

```python
x_train = x_train.astype('float32') / 255.0
x_test  = x_test.astype('float32') / 255.0
```

---

# What is Normalization?

Converts pixel values:
```text
0–255 → 0–1
```

---

# Formula

:contentReference[oaicite:0]{index=0}

---

# Why Normalize Data?

Benefits:
- Faster training
- Better convergence
- Stable learning

---

# 🔄 Cell 6 — Reshape Images

```python
x_train = x_train.reshape(-1, 28, 28, 1)
```

---

# Explanation

CNN requires:
```text
4D input tensor
```

---

# Shape Meaning

```text
(number_of_images,
 width,
 height,
 channels)
```

---

# Why Channel = 1?

Because images are:
```text
Grayscale
```

---

# Why -1 Used?

TensorFlow automatically calculates:
```text
Number of images
```

---

# 📏 Cell 7 — Check Shapes

```python
print(x_train.shape)
```

---

# Output Example

```text
(60000, 28, 28, 1)
```

---

# Meaning

| Value | Meaning |
|------|----------|
| 60000 | Images |
| 28 | Width |
| 28 | Height |
| 1 | Channel |

---

# 🧠 Cell 8 — Build CNN Model

```python
model = keras.Sequential([
```

---

# What is Sequential Model?

Layers added:
```text
One after another
```

---

# 🔍 First Convolution Layer

```python
keras.layers.Conv2D(
32,
(3,3),
activation='relu',
input_shape=(28,28,1)
)
```

---

# What is Conv2D?

Convolution layer extracts:
- Edges
- Shapes
- Features

from images.

---

# 32 Filters

```python
32
```

Means:
```text
32 feature detectors
```

---

# Kernel Size

```python
(3,3)
```

Small scanning window.

---

# Input Shape

```python
(28,28,1)
```

Represents:
- Width = 28
- Height = 28
- Grayscale channel = 1

---

# ReLU Activation

Formula:

:contentReference[oaicite:1]{index=1}

---

# Why ReLU Used?

Advantages:
- Faster learning
- Efficient computation
- Avoids vanishing gradient

---

# 📉 MaxPooling Layer

```python
keras.layers.MaxPooling2D((2,2))
```

---

# What is MaxPooling?

Reduces feature map dimensions.

Example:
```text
4×4 → 2×2
```

---

# Why Pooling Used?

Benefits:
- Reduces computation
- Reduces overfitting
- Keeps important features

---

# 🚫 Dropout Layer

```python
keras.layers.Dropout(0.25)
```

---

# What is Dropout?

Randomly disables:
```text
25% neurons
```

during training.

---

# Why Dropout Used?

Prevents:
- Overfitting
- Memorization

---

# 🔍 Second Convolution Layer

```python
keras.layers.Conv2D(
64,
(3,3),
activation='relu'
)
```

---

# Explanation

Uses:
```text
64 filters
```

for deeper feature extraction.

---

# 🔍 Third Convolution Layer

```python
keras.layers.Conv2D(
128,
(3,3),
activation='relu'
)
```

---

# Explanation

Detects:
- Complex image patterns
- Detailed fashion features

---

# 📄 Flatten Layer

```python
keras.layers.Flatten()
```

---

# What is Flatten?

Converts:
```text
2D feature maps → 1D vector
```

---

# Why Flatten Needed?

Dense layers require:
```text
1D input
```

---

# 🧠 Dense Layer

```python
keras.layers.Dense(
128,
activation='relu'
)
```

---

# Purpose

Performs:
- Final learning
- Classification preparation

---

# 🎯 Output Layer

```python
keras.layers.Dense(
10,
activation='softmax'
)
```

---

# Why 10 Neurons?

Because:
```text
10 fashion classes exist
```

---

# Softmax Activation

Formula:

:contentReference[oaicite:2]{index=2}

---

# Why Softmax Used?

Softmax:
- Converts outputs into probabilities
- Used for multiclass classification

---

# 📋 Cell 9 — Model Summary

```python
model.summary()
```

---

# Purpose

Displays:
- CNN architecture
- Output shapes
- Parameters

---

# ⚙️ Cell 10 — Compile Model

```python
model.compile(
optimizer='adam',
loss='sparse_categorical_crossentropy',
metrics=['accuracy']
)
```

---

# Adam Optimizer

Used for:
- Weight updates
- Faster convergence

---

# sparse_categorical_crossentropy

Used because:
- Multiple classes exist
- Labels are integer encoded

---

# Loss Formula

:contentReference[oaicite:3]{index=3}

---

# Accuracy Metric

Measures:
```text
Correct predictions percentage
```

---

# 🏋️ Cell 11 — Train Model

```python
history = model.fit(
x_train,
y_train,
epochs=10,
validation_data=(x_test,y_test)
)
```

---

# epochs=10

Dataset processed:
```text
10 times
```

---

# validation_data

Used to:
- Monitor accuracy
- Detect overfitting

---

# Batch Processing

Default batch size:
```text
32 samples
```

---

# HPC Perspective

CNN training involves:
- Matrix multiplication
- Parallel GPU operations
- Tensor computations

---

# 📊 Cell 12 — Evaluate Model

```python
test_loss, test_acc =
model.evaluate(x_test, y_test)
```

---

# Purpose

Evaluates:
- Test accuracy
- Test loss

---

# Example Output

```text
Accuracy = 90%
```

Means:
```text
90 out of 100 predictions correct
```

---

# 📈 Cell 13 — Accuracy Graph

```python
plt.plot(history.history['accuracy'])
```

---

# Purpose

Displays:
- Training accuracy
- Validation accuracy

---

# Why Graph Important?

Helps analyze:
- Learning progress
- Overfitting
- Model performance

---

# 🔮 Cell 14 — Predict Image

```python
prediction = model.predict(x_test)
```

---

# Purpose

Predicts:
```text
Fashion class probabilities
```

---

# np.argmax()

```python
np.argmax(prediction[0])
```

Returns:
```text
Highest probability class
```

---

# 🖼️ Cell 15 — Display Predicted Image

```python
plt.imshow(x_test[0].reshape(28,28))
```

---

# Purpose

Displays:
- Test image
- Predicted label

---

# CNN Concepts Used

| Concept | Purpose |
|----------|----------|
| CNN | Image classification |
| Conv2D | Feature extraction |
| MaxPooling | Dimension reduction |
| Flatten | Convert 2D → 1D |
| Dense Layer | Classification |
| Dropout | Prevent overfitting |
| ReLU | Activation function |
| Softmax | Multiclass probability |

---

# HPC Concepts Used

| HPC Concept | Usage |
|-------------|-------|
| Parallel Processing | Tensor operations |
| GPU Acceleration | CNN training |
| Matrix Multiplication | Deep learning |
| CUDA Backend | TensorFlow optimization |
| High Throughput Computing | Image processing |

---

# Sequential vs Parallel Processing

| Sequential CPU | Parallel GPU |
|----------------|-------------|
| Slower | Faster |
| Limited cores | Thousands of GPU cores |
| Sequential operations | Massive parallel operations |

---

# Important Viva Questions

# 1. What is Classification?

Process of categorizing data into classes.

---

# 2. What is Multiclass Classification?

Classification involving more than two classes.

---

# 3. What is CNN?

Convolutional Neural Network used for image processing.

---

# 4. Why CNN used for images?

Because CNN automatically extracts image features.

---

# 5. What is Conv2D?

Layer used for feature extraction.

---

# 6. What is Pooling?

Technique used to reduce dimensions.

---

# 7. What is Flatten Layer?

Converts feature maps into vectors.

---

# 8. What is Dropout?

Technique used to prevent overfitting.

---

# 9. Why Softmax used?

For multiclass probability prediction.

---

# 10. What is Adam Optimizer?

Optimization algorithm used in deep learning.

---

# 11. What is Epoch?

One complete training cycle.

---

# 12. What is Batch Size?

Number of samples processed together.

---

# 13. Why normalize images?

To improve training performance.

---

# 14. What is Fashion MNIST?

Dataset containing fashion clothing images.

---

# 15. Why GPUs used in CNN?

For faster parallel computation.

---

# Conclusion

This program successfully performs:

- Fashion Image Classification
- Multiclass Classification
- Deep Learning using CNN

using:
- TensorFlow
- Keras
- Fashion MNIST Dataset

The CNN model learns image features and classifies:
- T-shirts
- Dresses
- Shoes
- Bags
- Sandals
and other clothing categories.

This practical demonstrates:
- CNN architecture
- Deep learning workflow
- Image preprocessing
- Multiclass classification
- HPC concepts in AI systems