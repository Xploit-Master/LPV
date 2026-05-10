# Multiclass Classification using Deep Neural Networks (DNN)

Based on the practical provided in the uploaded document. :contentReference[oaicite:0]{index=0}

---

# 📌 Aim

To implement Multiclass Classification using Deep Neural Networks (DNN) on OCR / MNIST handwritten digit dataset.

---

# 🎯 Objective

Students should be able to:

- Understand Multiclass Classification
- Understand Deep Neural Networks (DNN)
- Perform image classification using DNN
- Train and evaluate multiclass classification models
- Understand neural network architecture
- Learn image preprocessing techniques

---

# 📖 Theory

# What is Classification?

Classification is a supervised machine learning technique where a model predicts categories or classes from input data.

Examples:
- Spam / Not Spam
- Cat / Dog
- Positive / Negative
- Digit Recognition

---

# What is Multiclass Classification?

Multiclass Classification is a classification problem where output belongs to more than two classes.

---

# Binary vs Multiclass Classification

| Binary Classification | Multiclass Classification |
|----------------------|---------------------------|
| Two classes | More than two classes |
| Example: Yes/No | Example: Digits 0–9 |
| Output neurons = 1 | Output neurons > 2 |

---

# Example of Multiclass Classification

Examples include:

| Problem | Classes |
|---------|----------|
| Digit Recognition | 0–9 |
| Animal Classification | Cat, Dog, Bird |
| News Classification | Sports, Politics, Tech |
| Disease Detection | Multiple diseases |

---

# OCR Dataset

OCR means:
```text
Optical Character Recognition
```

OCR systems recognize:
- Handwritten characters
- Printed text
- Digits

---

# What is MNIST Dataset?

MNIST is one of the most popular handwritten digit datasets used in Deep Learning.

Dataset contains:
- 70,000 grayscale images
- Digits from 0 to 9

---

# Dataset Division

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

# Why MNIST Dataset is Important?

MNIST is used for:
- Image classification
- Deep learning experiments
- Neural network training
- Computer vision research

---

# What is Deep Neural Network (DNN)?

Deep Neural Network is a machine learning model inspired by the human brain.

It contains:
- Input Layer
- Hidden Layers
- Output Layer

---

# Structure of DNN

```text
Input Layer → Hidden Layers → Output Layer
```

---

# Input Layer

Receives image pixel values.

In this practical:
```text
28 × 28 = 784 input neurons
```

---

# Hidden Layers

Responsible for:
- Pattern learning
- Feature extraction
- Complex computations

---

# Output Layer

Contains:
```text
10 neurons
```

representing:
```text
Digits 0–9
```

---

# Why DNN is Used?

Deep Neural Networks:
- Learn image patterns
- Detect handwritten digits
- Improve classification accuracy
- Handle complex data

---

# How DNN Works for Image Classification

# Step 1: Input Image

Image entered into neural network.

Example:
```text
Handwritten digit 5
```

---

# Step 2: Preprocessing

Image converted into:
- Numerical arrays
- Normalized values

---

# Step 3: Feature Learning

Hidden layers learn:
- Edges
- Shapes
- Patterns

---

# Step 4: Classification

Output layer predicts:
```text
0–9 digit class
```

---

# What are Pixels?

Image consists of tiny elements called pixels.

Each pixel stores:
```text
Intensity value
```

Range:
```text
0 to 255
```

---

# Pixel Meaning

| Value | Meaning |
|-------|----------|
| 0 | Black |
| 255 | White |
| Between 0–255 | Shades of gray |

---

# Why Images Reshaped?

Original shape:
```text
(28, 28)
```

Converted to:
```text
784-dimensional vector
```

---

# Why Reshape Needed?

Neural networks accept:
```text
1D input vectors
```

not 2D images directly.

---

# Data Normalization

Pixel values divided by:
```text
255
```

Formula:

:contentReference[oaicite:1]{index=1}

---

# Why Normalization Important?

Normalization:
- Speeds training
- Improves accuracy
- Stabilizes learning

---

# One-Hot Encoding

Labels converted into binary vectors.

Example:

Digit:
```text
5
```

becomes:

```text
[0 0 0 0 0 1 0 0 0 0]
```

---

# Why One-Hot Encoding Used?

Multiclass classification requires:
- Multiple output classes
- Categorical labels

---

# Dense Layer

Dense layer means:
```text
Every neuron connected to every neuron
in previous layer
```

---

# Activation Functions

Activation functions introduce:
- Non-linearity
- Learning capability

---

# ReLU Activation Function

Used in hidden layers.

Formula:

:contentReference[oaicite:2]{index=2}

---

# Why ReLU Used?

Advantages:
- Faster training
- Prevents vanishing gradient
- Computationally efficient

---

# Softmax Function

Used in output layer.

Formula:

:contentReference[oaicite:3]{index=3}

---

# Why Softmax Used?

Softmax:
- Converts outputs into probabilities
- Probability sum = 1
- Best for multiclass classification

---

# Dropout Layer

Randomly disables neurons during training.

Example:
```text
Dropout = 0.2
```

means:
```text
20% neurons disabled randomly
```

---

# Why Dropout Used?

Prevents:
- Overfitting
- Memorization

Improves:
- Generalization

---

# RMSprop Optimizer

RMSprop =
```text
Root Mean Square Propagation
```

Used to:
- Optimize weights
- Improve convergence speed

---

# Why RMSprop Used?

Advantages:
- Faster convergence
- Adaptive learning rate
- Good for neural networks

---

# Loss Function

Used:
```text
categorical_crossentropy
```

---

# Why categorical_crossentropy Used?

Because:
- Multiple output classes exist
- Labels are one-hot encoded

---

# Categorical Cross Entropy Formula

:contentReference[oaicite:4]{index=4}

---

# Batch Size

Batch size defines:
```text
How many samples processed together
```

Example:
```text
batch_size = 128
```

---

# Why Batch Size Important?

Large batch size:
- Faster training
- More memory usage

Small batch size:
- Slower training
- Better generalization

---

# What is Epoch?

One complete pass through training dataset.

Example:
```text
epochs = 20
```

means:
```text
Model sees dataset 20 times
```

---

# Validation Data

Validation dataset used to:
- Monitor model performance
- Detect overfitting

---

# Model Architecture Used

```text
Input Layer (784)
        ↓
Dense Layer (512)
        ↓
Dropout
        ↓
Dense Layer (512)
        ↓
Dropout
        ↓
Output Layer (10)
```

---

# Concepts Used in This Practical

| Concept | Purpose |
|----------|----------|
| Deep Learning | Automatic feature learning |
| Multiclass Classification | Multiple category prediction |
| Neural Networks | Pattern learning |
| ReLU | Hidden layer activation |
| Softmax | Output probability |
| Dropout | Prevent overfitting |
| RMSprop | Weight optimization |
| One-Hot Encoding | Multiclass labels |
| Normalization | Scale input values |

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
One-Hot Encoding
      ↓
Build Neural Network
      ↓
Compile Model
      ↓
Train Model
      ↓
Evaluate Model
```

---

# HPC Perspective

Deep learning requires:
- Large matrix operations
- Millions of calculations
- Parallel tensor processing

TensorFlow internally uses:
- GPU acceleration
- Parallel computation
- Optimized linear algebra

This makes Deep Learning suitable for:
- High Performance Computing (HPC)

---

# Why GPU Acceleration Important?

Neural networks involve:
- Matrix multiplications
- Parallel mathematical operations
- Massive computations

GPU performs these operations much faster than CPU.

---

# Sequential vs Parallel Processing

| Sequential CPU | Parallel GPU |
|----------------|-------------|
| One operation at a time | Thousands simultaneously |
| Slower | Faster |
| Limited scalability | High scalability |

---

# Advantages of DNN

- High accuracy
- Learns complex patterns
- Automatic feature extraction
- Efficient image classification

---

# Limitations

- Requires high computation
- Needs large datasets
- Longer training time
- Risk of overfitting

---

# Applications of Multiclass Classification

- Handwritten digit recognition
- Face recognition
- Medical diagnosis
- Image classification
- Speech recognition

---

# Important Viva Questions

# 1. What is Multiclass Classification?

Classification involving more than two classes.

---

# 2. What is MNIST Dataset?

Dataset of handwritten digits from 0–9.

---

# 3. Why images reshaped?

Neural networks require 1D input vectors.

---

# 4. Why normalization used?

To scale pixel values between 0 and 1.

---

# 5. What is One-Hot Encoding?

Converting labels into binary vectors.

---

# 6. What is ReLU?

Activation function used in hidden layers.

---

# 7. What is Softmax?

Function converting outputs into probabilities.

---

# 8. Why Softmax used?

Because this is multiclass classification.

---

# 9. What is Dropout?

Technique used to prevent overfitting.

---

# 10. What is RMSprop?

Optimization algorithm for neural networks.

---

# 11. What is Batch Size?

Number of samples processed together.

---

# 12. What is Epoch?

One complete training cycle.

---

# 13. Why categorical_crossentropy used?

Because output contains multiple classes.

---

# 14. Why GPU used in Deep Learning?

For faster parallel computation.

---

# 15. What is Deep Neural Network?

Neural network with multiple hidden layers.

---

# Conclusion

In this practical, Multiclass Classification was implemented using:

- Deep Neural Networks
- MNIST OCR Dataset
- TensorFlow and Keras

The model successfully classified handwritten digits from:
```text
0 to 9
```

This practical helps understand:
- Image classification
- Deep learning workflow
- Neural network training
- Multiclass classification
- HPC concepts in AI systems