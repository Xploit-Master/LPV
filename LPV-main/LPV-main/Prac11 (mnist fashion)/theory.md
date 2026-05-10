# Fashion MNIST Classification using CNN and Deep Neural Networks

Based on the practical provided in the uploaded document. :contentReference[oaicite:0]{index=0}

---

# 📌 Aim

To implement a Convolutional Neural Network (CNN) using Deep Learning to classify fashion clothing images from the Fashion MNIST dataset into different categories.

---

# 🎯 Objective

Students should be able to:

- Understand image classification
- Understand CNN architecture
- Perform multiclass classification
- Train Deep Neural Networks
- Classify fashion clothing categories using Fashion MNIST dataset

---

# 📖 Theory

# What is Classification?

Classification is a supervised machine learning technique where data is categorized into predefined classes.

The model learns patterns from labeled data and predicts categories for unseen data.

---

# Examples of Classification

| Application | Classes |
|-------------|----------|
| Email Filtering | Spam / Not Spam |
| Disease Detection | Disease / No Disease |
| Face Recognition | Multiple Persons |
| Fashion Classification | Shirt, Shoe, Bag, etc. |

---

# Types of Classification

| Type | Description |
|------|-------------|
| Binary Classification | Two classes |
| Multiclass Classification | More than two classes |

---

# What is Multiclass Classification?

Multiclass classification means predicting one class from multiple possible output classes.

Example:
```text
T-shirt
Trouser
Bag
Sandal
Sneaker
```

---

# What is Fashion MNIST Dataset?

Fashion MNIST is a dataset of clothing images used for image classification tasks.

It contains:
- 70,000 grayscale images
- 10 fashion categories

---

# Dataset Distribution

| Dataset | Images |
|---------|---------|
| Training Set | 60,000 |
| Testing Set | 10,000 |

---

# Image Size

Each image size:
```text
28 × 28 pixels
```

---

# Fashion Categories

| Label | Category |
|------|-----------|
| 0 | T-shirt/top |
| 1 | Trouser |
| 2 | Pullover |
| 3 | Dress |
| 4 | Coat |
| 5 | Sandal |
| 6 | Shirt |
| 7 | Sneaker |
| 8 | Bag |
| 9 | Ankle Boot |

---

# Why Fashion MNIST Used?

Fashion MNIST is:
- More challenging than digit MNIST
- Widely used for CNN learning
- Useful for image classification experiments

---

# What is CNN?

CNN stands for:
```text
Convolutional Neural Network
```

CNN is a type of Deep Neural Network specially designed for image processing tasks.

---

# Why CNN Used for Images?

CNN automatically learns:
- Edges
- Shapes
- Textures
- Patterns

from images.

---

# CNN Architecture

Typical CNN contains:

```text
Input Layer
      ↓
Convolution Layer
      ↓
Pooling Layer
      ↓
Flatten Layer
      ↓
Dense Layer
      ↓
Output Layer
```

---

# Convolution Layer

Convolution layer extracts features from images using filters.

Example features:
- Corners
- Edges
- Curves
- Textures

---

# Convolution Formula

:contentReference[oaicite:1]{index=1}

---

# Filters in CNN

Filters scan the image and detect patterns.

Example:
```text
3×3 filter
```

---

# Activation Function

Activation functions introduce non-linearity.

Most common:
```text
ReLU
```

---

# ReLU Function

Formula:

:contentReference[oaicite:2]{index=2}

---

# Why ReLU Used?

Advantages:
- Faster training
- Efficient computation
- Avoids vanishing gradient

---

# Pooling Layer

Pooling reduces image dimensions.

Most common:
```text
MaxPooling
```

---

# MaxPooling Example

```text
4×4 image → 2×2 image
```

---

# Why Pooling Used?

Benefits:
- Reduces computation
- Reduces overfitting
- Keeps important features

---

# Flatten Layer

Flatten converts:
```text
2D feature maps → 1D vector
```

Required before Dense layers.

---

# Dense Layer

Dense layer means:
```text
Every neuron connected to every neuron
```

Used for:
- Classification
- Final prediction

---

# Dropout Layer

Dropout randomly disables neurons during training.

Example:
```text
Dropout = 0.25
```

means:
```text
25% neurons disabled randomly
```

---

# Why Dropout Used?

Prevents:
- Overfitting
- Memorization

Improves:
- Generalization

---

# Softmax Activation Function

Used in output layer.

Formula:

:contentReference[oaicite:3]{index=3}

---

# Why Softmax Used?

Softmax:
- Converts outputs into probabilities
- Used in multiclass classification

---

# Data Preprocessing

Before training:
- Pixel values normalized
- Images reshaped

---

# Pixel Normalization

Formula:

:contentReference[oaicite:4]{index=4}

---

# Why Normalize Pixels?

Original range:
```text
0–255
```

Normalized range:
```text
0–1
```

Benefits:
- Faster training
- Better convergence

---

# Image Reshaping

Images reshaped into:
```text
(28,28,1)
```

Where:
- 28 = width
- 28 = height
- 1 = grayscale channel

---

# How CNN Works on Classification

# Step 1

Input image given to CNN.

---

# Step 2

Convolution layers extract features.

---

# Step 3

Pooling layers reduce dimensions.

---

# Step 4

Flatten converts feature maps into vectors.

---

# Step 5

Dense layers perform classification.

---

# Step 6

Softmax predicts probability of each class.

---

# Step 7

Highest probability becomes predicted class.

---

# Loss Function

Used:
```text
sparse_categorical_crossentropy
```

---

# Why sparse_categorical_crossentropy Used?

Because:
- Multiple classes exist
- Labels are integers

---

# Loss Formula

:contentReference[oaicite:5]{index=5}

---

# Optimizer

Used:
```text
Adam Optimizer
```

---

# What is Adam Optimizer?

Adam is an optimization algorithm used to:
- Update neural network weights
- Minimize loss function

---

# Advantages of Adam

- Fast convergence
- Adaptive learning rate
- Efficient training

---

# Epoch

Epoch means:
```text
One complete training cycle
```

Example:
```text
epochs = 10
```

means:
```text
Dataset processed 10 times
```

---

# Batch Size

Batch size means:
```text
Number of samples processed together
```

Default:
```text
32 samples
```

---

# Validation Data

Validation data used to:
- Monitor training
- Detect overfitting

---

# Model Evaluation

After training:
- Model tested on unseen images
- Accuracy calculated

---

# Accuracy

Accuracy means:
```text
Percentage of correct predictions
```

Example:
```text
90% accuracy
```

means:
```text
90 out of 100 predictions correct
```

---

# Deep Learning Workflow

```text
Load Dataset
      ↓
Preprocessing
      ↓
Normalization
      ↓
Reshaping
      ↓
Build CNN Model
      ↓
Compile Model
      ↓
Train Model
      ↓
Evaluate Model
      ↓
Prediction
```

---

# HPC Perspective

This practical belongs to:
- Deep Learning
- Computer Vision
- High Performance Computing (HPC)

because CNN training requires:
- Massive matrix multiplication
- Parallel tensor computation
- GPU acceleration

TensorFlow internally uses:
- CUDA
- GPU cores
- Parallel processing

---

# Why GPU Used?

CNN training involves:
- Millions of computations
- Matrix operations
- Parallel calculations

GPU performs these tasks faster than CPU.

---

# Sequential vs Parallel Processing

| Sequential CPU | Parallel GPU |
|----------------|-------------|
| Slower | Faster |
| Limited cores | Thousands of GPU cores |
| Sequential operations | Parallel operations |

---

# Applications of CNN

| Application | Usage |
|-------------|-------|
| Face Recognition | Identity verification |
| Medical Imaging | Disease detection |
| Autonomous Cars | Object detection |
| Fashion Classification | Clothing recognition |
| Security Systems | Surveillance |

---

# Advantages of CNN

- High image accuracy
- Automatic feature extraction
- Efficient image recognition
- Handles complex patterns

---

# Limitations

- Requires high computation
- Needs large datasets
- Training time is high

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

# 5. What is Convolution Layer?

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

Optimization algorithm for neural networks.

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

In this practical, Fashion MNIST Dataset was classified using:

- Convolutional Neural Network (CNN)
- Deep Learning
- TensorFlow and Keras

The model successfully classified fashion clothing images into:
- T-shirt
- Trouser
- Dress
- Bag
- Sneaker
- Sandal
and other categories.

This practical demonstrates:
- Multiclass Classification
- CNN architecture
- Image preprocessing
- Deep learning workflow
- HPC concepts in AI systems