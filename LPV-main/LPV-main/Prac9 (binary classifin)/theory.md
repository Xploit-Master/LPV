# Binary Classification using Deep Neural Networks on IMDB Dataset

Based on the practical provided in the uploaded document. :contentReference[oaicite:0]{index=0}

---

# 📌 Aim

To implement Binary Classification using Deep Neural Networks (DNN) for classifying IMDB movie reviews into positive and negative sentiments.

---

# 🎯 Objective

Students should be able to:

- Understand Binary Classification
- Understand Deep Neural Networks (DNN)
- Perform Sentiment Analysis using IMDB Dataset
- Train and evaluate NLP classification models
- Understand text preprocessing techniques
- Learn deep learning workflow for Natural Language Processing (NLP)

---

# 📖 Theory

# What is Classification?

Classification is a supervised machine learning technique used to categorize data into predefined classes.

The model learns from labeled training data and predicts categories for unseen data.

---

# Example of Classification

| Input | Output |
|-------|---------|
| Email content | Spam / Not Spam |
| Medical report | Disease / No Disease |
| Movie review | Positive / Negative |
| Image | Cat / Dog |

---

# What is Binary Classification?

Binary Classification means:
- Only two possible output classes

Example:
- Positive / Negative
- Yes / No
- True / False
- Spam / Not Spam

In this practical:
- 1 → Positive Review
- 0 → Negative Review

---

# Binary Classification Formula

:contentReference[oaicite:1]{index=1}

---

# What is Sentiment Analysis?

Sentiment Analysis is Natural Language Processing (NLP) technique used to determine emotional tone of text.

It identifies whether text is:
- Positive
- Negative
- Neutral

---

# What is IMDB Dataset?

IMDB Dataset is a large movie review dataset used for sentiment analysis.

Dataset contains:
- 50,000 movie reviews
- 25,000 training reviews
- 25,000 testing reviews

Each review is labeled:
- Positive (1)
- Negative (0)

---

# Why IMDB Dataset is Popular?

IMDB dataset is widely used because:
- Large dataset
- Real-world reviews
- Good benchmark for NLP
- Suitable for Deep Learning experiments

---

# Nature of IMDB Reviews

Reviews contain:
- Human language
- Opinions
- Emotions
- Slang
- Complex sentence structures

This makes sentiment classification challenging.

---

# What is Deep Neural Network (DNN)?

Deep Neural Network is a machine learning model inspired by the human brain.

It contains:
- Input Layer
- Hidden Layers
- Output Layer

---

# Structure of Deep Neural Network

```text
Input Layer → Hidden Layers → Output Layer
```

---

# Input Layer

Receives input features.

In this practical:
- Input = Movie review text vectors

---

# Hidden Layers

Learn:
- Patterns
- Features
- Relationships

Hidden layers improve classification accuracy.

---

# Output Layer

Produces final classification.

For binary classification:
- One neuron used

Output:
- 0 → Negative
- 1 → Positive

---

# Why Deep Learning is Used for NLP?

Traditional machine learning struggles with:
- Complex language
- Context understanding
- Large vocabulary

Deep Learning:
- Learns text patterns automatically
- Handles large datasets efficiently
- Improves prediction accuracy

---

# How Deep Neural Network Works on Classification

# Step 1: Input Text

Movie review entered into model.

Example:
```text
"This movie was amazing"
```

---

# Step 2: Text Preprocessing

Text converted into:
- Numbers
- Vectors
- Tensors

Because neural networks understand only numerical data.

---

# Step 3: Feature Extraction

Hidden layers learn:
- Important words
- Sentiment patterns
- Relationships between words

---

# Step 4: Classification

Output layer predicts:
- Positive sentiment
- Negative sentiment

---

# Step 5: Weight Optimization

Weights updated using:
- Backpropagation
- Gradient Descent

---

# What is Vocabulary?

Vocabulary is collection of unique words.

In this practical:
```text
Top 10,000 words used
```

---

# Why Vocabulary Size Limited?

Reducing vocabulary:
- Reduces computation
- Speeds training
- Reduces memory usage

---

# What is Word Indexing?

Words converted into integer numbers.

Example:

| Word | Index |
|------|-------|
| the | 1 |
| movie | 25 |
| good | 142 |

---

# Why Text Converted into Numbers?

Neural networks process:
- Numerical tensors
- Not raw text

---

# What is Vectorization?

Vectorization converts text into numerical vectors.

Example:

```text
Good movie
```

may become:

```text
[0,1,0,1,0,...]
```

---

# Why Vectorization Important?

Neural networks require:
- Fixed-size numerical input

Vectorization enables:
- Mathematical computations
- Neural network processing

---

# One-Hot Encoding

Reviews converted into binary vectors.

Example:

| Word Present | Value |
|--------------|-------|
| Yes | 1 |
| No | 0 |

---

# What is Padding?

Padding adds zeros to shorter reviews.

Example:

```text
[1,5,7]
```

becomes:

```text
[1,5,7,0,0,0]
```

---

# Why Padding Needed?

Neural networks require:
- Same input size for all reviews

---

# What is Embedding?

Embedding converts words into dense numerical representations.

Embeddings capture:
- Semantic meaning
- Relationships between words

---

# Activation Functions Used

# ReLU Activation

Used in hidden layers.

Formula:

:contentReference[oaicite:2]{index=2}

---

# Why ReLU Used?

Advantages:
- Fast computation
- Prevents vanishing gradient
- Efficient training

---

# Sigmoid Activation

Used in output layer.

Formula:

:contentReference[oaicite:3]{index=3}

---

# Why Sigmoid Used?

Produces output between:
```text
0 and 1
```

Perfect for binary classification probability.

---

# What is Binary Cross Entropy?

Loss function used for binary classification.

Formula:

:contentReference[oaicite:4]{index=4}

---

# Purpose of Binary Cross Entropy

Measures:
- Difference between predicted and actual labels

Lower loss means:
- Better predictions

---

# What is Optimizer?

Optimizer updates neural network weights to minimize loss.

---

# Adam Optimizer

Most commonly used optimizer.

Advantages:
- Fast convergence
- Adaptive learning rate
- Efficient training

---

# What is Epoch?

One complete pass through training dataset.

Example:
```text
Epoch = 1
```
means model sees entire training dataset once.

---

# What is Batch Size?

Number of samples processed together.

Example:
```text
Batch Size = 500
```

500 reviews processed at one time.

---

# What is Validation Split?

Part of training data reserved for validation.

Purpose:
- Monitor performance
- Detect overfitting

---

# What is Overfitting?

Model memorizes training data instead of learning patterns.

Result:
- Poor performance on new data

---

# What is Dropout Layer?

Dropout randomly disables neurons during training.

Example:
```text
Dropout = 0.3
```

means:
```text
30% neurons disabled randomly
```

---

# Why Dropout Used?

Prevents:
- Overfitting
- Model memorization

Improves:
- Generalization

---

# What is Early Stopping?

Stops training automatically when:
- Model stops improving

---

# Why Early Stopping Used?

Prevents:
- Overtraining
- Wasting computation time
- Overfitting

---

# Model Architecture Used

```text
Input Layer → Dense → Dropout →
Dense → Dropout →
Dense → Output Layer
```

---

# Output Layer

Uses:
```text
1 neuron + sigmoid activation
```

Because:
- Binary classification problem

---

# Deep Learning Workflow Used

```text
Load Dataset
      ↓
Preprocessing
      ↓
Vectorization
      ↓
Train-Test Split
      ↓
Build Neural Network
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

# Concepts Used in This Practical

| Concept | Purpose |
|----------|----------|
| NLP | Text processing |
| Binary Classification | Positive/Negative prediction |
| Deep Learning | Automatic learning |
| Neural Networks | Pattern extraction |
| Vectorization | Text to numerical conversion |
| Dropout | Prevent overfitting |
| ReLU | Hidden layer activation |
| Sigmoid | Output probability |
| Adam Optimizer | Weight optimization |
| Binary Cross Entropy | Loss calculation |

---

# Why Deep Learning Performs Better?

Deep learning:
- Learns automatically
- Captures complex language patterns
- Handles large datasets
- Improves sentiment classification accuracy

---

# Advantages of Deep Neural Networks

- High accuracy
- Automatic feature extraction
- Handles large datasets
- Learns complex patterns

---

# Limitations

- Requires high computation
- Needs large training data
- Longer training time
- Risk of overfitting

---

# Applications of Sentiment Analysis

- Movie review analysis
- Product review analysis
- Social media monitoring
- Customer feedback analysis
- Opinion mining

---

# HPC Perspective

Deep Learning requires:
- Large matrix operations
- Massive computations
- Parallel execution

Frameworks like TensorFlow use:
- GPU acceleration
- Parallel tensor operations
- Optimized computation graphs

This makes Deep Learning suitable for:
- High Performance Computing (HPC)

---

# Why GPU Acceleration Important?

Neural networks involve:
- Millions of calculations
- Matrix multiplications
- Parallel mathematical operations

GPU executes these computations much faster than CPU.

---

# Sequential vs Parallel Processing

| Sequential | Parallel |
|------------|-----------|
| One operation at a time | Multiple operations simultaneously |
| Slower | Faster |
| CPU focused | GPU focused |
| Limited scalability | High scalability |

---

# Important Viva Questions

## 1. What is Classification?

A supervised learning technique used to categorize data into classes.

---

## 2. What is Binary Classification?

Classification involving only two output classes.

---

## 3. What is Sentiment Analysis?

Determining emotional tone of text.

---

## 4. What is IMDB Dataset?

Movie review dataset for sentiment analysis.

---

## 5. Why text converted into numbers?

Neural networks process numerical data only.

---

## 6. What is Vectorization?

Converting text into numerical vectors.

---

## 7. What is Padding?

Adding zeros to make equal input size.

---

## 8. What is ReLU?

Activation function used in hidden layers.

---

## 9. What is Sigmoid?

Activation function producing values between 0 and 1.

---

## 10. What is Binary Cross Entropy?

Loss function used for binary classification.

---

## 11. What is Adam Optimizer?

Optimization algorithm for neural networks.

---

## 12. What is Epoch?

One complete training cycle through dataset.

---

## 13. What is Batch Size?

Number of samples processed together.

---

## 14. What is Dropout?

Technique used to prevent overfitting.

---

## 15. What is Validation Split?

Part of training data reserved for validation.

---

# Conclusion

In this practical, Binary Classification was implemented using:

- Deep Neural Networks
- IMDB Movie Review Dataset
- NLP techniques

The model successfully classified movie reviews into:
- Positive reviews
- Negative reviews

This practical helps understand:
- Sentiment Analysis
- Natural Language Processing
- Deep Learning
- Binary Classification
- Neural Network training
- HPC concepts in AI