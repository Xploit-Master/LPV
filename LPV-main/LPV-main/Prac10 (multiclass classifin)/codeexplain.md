# Code Explanation – Multiclass Classification using CNN and Deep Neural Networks

This program performs:

- Multiclass Image Classification
- Deep Learning using CNN
- Plant Disease Detection

using TensorFlow and Keras.

The model predicts multiple plant disease categories using image classification.

---

# 📌 Introduction

This practical uses:
- Convolutional Neural Network (CNN)
- Deep Learning
- TensorFlow
- Image Processing

to classify plant leaf diseases into multiple categories.

This is a:
```text
Multiclass Classification Problem
```

because:
- More than two output classes exist.

---

# 🧠 HPC Perspective

This practical belongs to:
- Deep Learning
- Computer Vision
- High Performance Computing (HPC)

because CNN training involves:
- Massive matrix operations
- GPU acceleration
- Parallel tensor computation
- Large-scale image processing

TensorFlow internally uses:
- GPU cores
- CUDA acceleration
- Parallel processing

---

# 📦 Step 1: Import Libraries

```python
import tensorflow as tf
```

---

# TensorFlow

TensorFlow is a Deep Learning framework developed by Google.

Used for:
- Neural network creation
- GPU acceleration
- Tensor operations

---

# Sequential Model

```python
from tensorflow.keras.models import Sequential
```

Used to create:
```text
Sequential Neural Network
```

Layers are added one after another.

---

# CNN Layers

```python
from tensorflow.keras.layers import
Conv2D,
MaxPooling2D,
Flatten,
Dense,
Dropout
```

---

# Purpose of Each Layer

| Layer | Purpose |
|-------|----------|
| Conv2D | Feature extraction |
| MaxPooling2D | Reduce dimensions |
| Flatten | Convert 2D → 1D |
| Dense | Fully connected learning |
| Dropout | Prevent overfitting |

---

# ImageDataGenerator

```python
from tensorflow.keras.preprocessing.image import ImageDataGenerator
```

Used for:
- Image preprocessing
- Data augmentation
- Batch generation

---

# Matplotlib

```python
import matplotlib.pyplot as plt
```

Used for:
- Accuracy graph plotting

---

# 📂 Step 2: Dataset Paths

```python
train_path = "Plant_Disease_Dataset/train"
valid_path = "Plant_Disease_Dataset/valid"
test_path  = "Plant_Disease_Dataset/test"
```

---

# Explanation

Dataset divided into:

| Folder | Purpose |
|--------|----------|
| train | Model training |
| valid | Validation |
| test | Final testing |

---

# Why Dataset Split Needed?

Training set:
- Learns patterns

Validation set:
- Monitors training

Testing set:
- Measures final accuracy

---

# 🖼️ Step 3: Image Data Generator

```python
train_datagen = ImageDataGenerator(
    rescale=1./255,
    rotation_range=20,
    zoom_range=0.2,
    horizontal_flip=True
)
```

---

# What is Data Augmentation?

Artificially creating modified images.

Examples:
- Rotation
- Zoom
- Flipping

---

# Why Data Augmentation Used?

Improves:
- Generalization
- Accuracy

Reduces:
- Overfitting

---

# Rescaling

```python
rescale=1./255
```

Normalizes pixel values.

Formula:

:contentReference[oaicite:0]{index=0}

---

# Why Normalize Pixels?

Original pixel range:
```text
0 → 255
```

Normalized range:
```text
0 → 1
```

Benefits:
- Faster training
- Better convergence

---

# Rotation

```python
rotation_range=20
```

Randomly rotates image up to:
```text
20 degrees
```

---

# Zoom

```python
zoom_range=0.2
```

Random zoom augmentation.

---

# Horizontal Flip

```python
horizontal_flip=True
```

Flips image horizontally.

---

# Validation/Test Generator

```python
valid_datagen = ImageDataGenerator(rescale=1./255)
```

Only normalization applied.

No augmentation.

---

# 📁 Step 4: Load Images

```python
train_data = train_datagen.flow_from_directory(
    train_path,
    target_size=(128, 128),
    batch_size=32,
    class_mode='categorical'
)
```

---

# Explanation

Loads training images from folders.

---

# target_size

```python
(128,128)
```

All images resized to:
```text
128 × 128 pixels
```

---

# Why Resize Images?

CNN requires:
```text
Fixed image dimensions
```

---

# batch_size

```python
32
```

Processes:
```text
32 images together
```

---

# class_mode='categorical'

Used for:
```text
Multiclass Classification
```

Labels converted into:
```text
One-hot encoded vectors
```

---

# Example

If 4 classes exist:

```text
Class 2
```

becomes:

```text
[0 0 1 0]
```

---

# 🧠 Step 5: Build CNN Model

```python
model = Sequential()
```

Creates sequential CNN architecture.

---

# 🔍 Convolution Layer 1

```python
model.add(
Conv2D(
32,
(3,3),
activation='relu',
input_shape=(128,128,3)
))
```

---

# What is Conv2D?

Convolution layer extracts:
- Edges
- Shapes
- Patterns

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

Small window scanning image.

---

# Input Shape

```python
(128,128,3)
```

Represents:
- Width = 128
- Height = 128
- RGB channels = 3

---

# ReLU Activation

Formula:

:contentReference[oaicite:1]{index=1}

---

# Why ReLU Used?

Advantages:
- Faster learning
- Efficient computation
- Prevents vanishing gradient

---

# 📉 Max Pooling Layer

```python
model.add(MaxPooling2D(2,2))
```

---

# What is MaxPooling?

Reduces image dimensions.

Example:
```text
4×4 → 2×2
```

---

# Why Pooling Used?

Benefits:
- Reduces computation
- Extracts important features
- Reduces overfitting

---

# 🔍 Convolution Layer 2

```python
model.add(Conv2D(64, (3,3), activation='relu'))
```

---

# Explanation

Now:
```text
64 feature detectors
```

used for deeper feature extraction.

---

# 🔍 Convolution Layer 3

```python
model.add(Conv2D(128, (3,3), activation='relu'))
```

---

# Explanation

Further learns:
- Complex patterns
- Disease characteristics

---

# 📄 Flatten Layer

```python
model.add(Flatten())
```

---

# What is Flatten?

Converts:
```text
2D feature maps → 1D vector
```

Needed before Dense layers.

---

# 🧠 Fully Connected Layer

```python
model.add(Dense(128, activation='relu'))
```

---

# Purpose

Performs:
- Final feature learning
- Classification preparation

---

# 🚫 Dropout Layer

```python
model.add(Dropout(0.5))
```

---

# What is Dropout?

Randomly disables:
```text
50% neurons
```

during training.

---

# Why Dropout Used?

Prevents:
- Overfitting
- Memorization

Improves:
- Generalization

---

# 🎯 Output Layer

```python
model.add(Dense(
train_data.num_classes,
activation='softmax'
))
```

---

# Why num_classes Used?

Automatically creates:
```text
One neuron per class
```

---

# Example

If dataset has:
```text
10 disease classes
```

output layer has:
```text
10 neurons
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

# ⚙️ Step 6: Compile Model

```python
model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy']
)
```

---

# Adam Optimizer

Used for:
- Weight updates
- Faster convergence

---

# categorical_crossentropy

Used because:
```text
Multiple output classes exist
```

Formula:

:contentReference[oaicite:3]{index=3}

---

# Accuracy Metric

Measures:
```text
Correct predictions percentage
```

---

# 📋 Model Summary

```python
model.summary()
```

Displays:
- Layers
- Parameters
- Shapes

---

# 🏋️ Step 7: Train Model

```python
history = model.fit(
    train_data,
    epochs=3,
    validation_data=valid_data
)
```

---

# epochs=3

Entire dataset processed:
```text
3 times
```

---

# Validation Data

Used to:
- Monitor accuracy
- Detect overfitting

---

# HPC Perspective

CNN training involves:
- Large matrix multiplication
- GPU acceleration
- Parallel tensor computation

---

# 📈 Step 8: Plot Accuracy Graph

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
- Model performance

---

# 🔥 CNN Concepts Used

| Concept | Purpose |
|----------|----------|
| CNN | Image feature extraction |
| Conv2D | Pattern detection |
| MaxPooling | Dimension reduction |
| Flatten | Convert 2D → 1D |
| Dense Layer | Classification |
| Dropout | Prevent overfitting |
| ReLU | Activation |
| Softmax | Multiclass probability |

---

# 🧠 HPC Concepts Used

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

# 1. What is Multiclass Classification?

Classification involving more than two classes.

---

# 2. What is CNN?

Convolutional Neural Network used for image processing.

---

# 3. Why CNN used for images?

Because CNN automatically extracts image features.

---

# 4. What is Conv2D?

Layer used for feature extraction.

---

# 5. What is MaxPooling?

Layer used to reduce dimensions.

---

# 6. What is Flatten layer?

Converts feature maps into vectors.

---

# 7. What is Dropout?

Technique to prevent overfitting.

---

# 8. Why Softmax used?

For multiclass probability prediction.

---

# 9. Why categorical_crossentropy used?

Because output has multiple classes.

---

# 10. What is Data Augmentation?

Artificially generating modified training images.

---

# 11. What is Batch Size?

Number of images processed together.

---

# 12. What is Epoch?

One complete training cycle.

---

# 13. Why GPUs used in CNN?

CNN training requires massive parallel computation.

---

# 14. What is ReLU?

Activation function used in hidden layers.

---

# 15. What is Adam Optimizer?

Optimization algorithm used in deep learning.

---

# Conclusion

This program successfully performs:

- Multiclass Classification
- Plant Disease Detection
- CNN based Image Classification

using:
- TensorFlow
- Keras
- Deep Neural Networks

The CNN model learns image features and predicts:
- Multiple disease classes

This practical demonstrates:
- Deep Learning workflow
- CNN architecture
- Image preprocessing
- Multiclass classification
- HPC concepts in AI systems