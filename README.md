# OOPP-Course-Project
OOPP Course Project, IV Semester, 2021.

## Title

E2E Supermarket Management

## Team

4D05

## Team Members

Aditya Vikram – 01FE19BCS220

Rishab Jain – 01FE19BCS228

Yash Raj – 01FE19BCS229

Harshita Hiremath – 01FE19BCS235

## Introduction

###  1.1 Overview of the Problem Statement

A supermarket is run by staffs, and staffs comprise of either cashiers, or assistants. There are various different products that a supermarket keeps in its inventory, but they be be segregated into three categories, namely, furniture, groceries, and clothing items. These items can be restocked by placing an order with the suppliers. When customers come to the supermarket to purchase goods, they can purchase a membership subscription with which they can earn loyalty points. There are three types of membership subscriptions, gold, silver and bronze, and they differ in terms of the points rewarded for each purchase. Our application will simulate the scenario described.

### 1.2 Features of the Application

#### Store Customer Data

Any person who comes to the store to purchase groceries will have to provide their details before doing so. Their data is collected so as to track their past purchases and allow them to accumulate membership points.

#### Enable Transactions

After customer has added desired products to their cart, they can go for billing, where one of the cashiers will facilitate the transaction.

#### Ability to Restock Products in the Inventory

An admin can place an order for procurement of products that will be out of stock soon. A supplier will automatically be assigned to who will deliver the required products. 

#### Get Assistance

A customer can get to know about the latest deals happening by choosing to get assistance. On doing so, a random assistant will inform the customer of the current promotions happening in the store.

####  View Purchase History

Any customer can request to view a list of the products they have purchased previously, associated with a unique transaction ID.

## Design

### 2.1 Class Diagrams

 #### Person

Super class for Customer, Staff, & Supplier.

#### Customer

Sub class of Person.

Aggregated with Transaction, and Membership. 

#### Staff

Sub class of Person.

Super class for Cashier, and Assistant.

Aggregated with Store, Transaction, & Date.

#### Supplier

Sub class of Person.

#### Cashier

Sub class of Staff.

#### Assistant

Sub class of staff.

#### Membership

Aggregated with Customer.

#### Store

Aggregated with Staff, and Inventory.

#### Inventory

Aggregated with Store, and Product.

#### Product

Super class for Furniture, Clothing & Grocery.

Aggregated with Inventory.

#### Grocery

Sub class of Product.

Aggregated with Date.

#### Furniture

Sub class of Product.

#### Clothing

Sub class of Product.

#### Gold Member

Sub class of Customer.

#### Silver Member

Sub class of Customer.

#### Bronze Member

Sub class of Customer.

#### Transaction

Aggregated with Staff, Customer, and Date.

### 2.2 main () Function

Data regarding the store will already be kept ready using constructor calls and compile-time initialization. User will be asked to login as a customer or as a staff. Accordingly, a set of pre-determined menu will be presented at each step to facilitate the task that needs to be performed.
