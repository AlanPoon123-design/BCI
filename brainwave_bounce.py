import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from fpdf import FPDF
from io import BytesIO
import time
import random

st.set_page_config(page_title="Brainwave Mood Simulator", layout="centered")

st.title("Simulated Brainwave Game Controller")
st.write("Welcome to your virtual BCI experience!  Use the sliders below to simulate your brainwave activity.")
st.write("Control your paddle by balancing your Alpha (relaxation) and Beta (focus) waves")

if 'ball_x' not in st.session_state:
    st.session_state.ball_x = 50
    st.session_state.ball_y = 25
    st.session_state.ball_vx = random.choice([-2.0, 2.0])
    st.session_state.ball_vy = random.choice([-2.0, 2.0])
    st.session_state.game_active = False
    st.session_state.alpha_strength = 50
    st.session_state.beta_strength = 50

st.header("Simulate Your Brainwaves")

alpha_strength = st.slider(
    "Alpha Wave Strength (Relaxation)",
    min_value=0,
    max_value=100,
    value=st.session_state.alpha_strength,
    step=1,
    help="Higher values simulate a more relaxed state."
)

beta_strength = st.slider(
    "Beta Wave Strength (Focus)",
    min_value=0,
    max_value=100,
    value=st.session_state.beta_strength,
    step=1,
    help="Higher values simulate a more focused or active brain state"
)

st.subheader("Current Simulated Brainwave Readings:")
st.write(f"Alpha: {alpha_strength} μV")
st.write(f"Beta: {beta_strength} μV")

st.markdown("---")

st.header("Paddle Game")

game_width = 100
game_height = 50
paddle_width = 20
paddle_height = 2
ball_radius = 2

brainwave_difference = beta_strength - alpha_strength

paddle_x_position = np.interp(
    brainwave_difference,
    [-100, 100],
    [0, game_width - paddle_width]
)

col1, col2 = st.columns(2)
with col1:
    if st.button("Start Game"):
        st.session_state.game_active = True
        st.session_state.ball_x = game_width / 2
        st.session_state.ball_y = game_height / 2
        st.session_state.ball_vx = random.choice([-2.0, 2.0])
        st.session_state.ball_vy = random.choice([-2.0, 2.0])
        st.rerun()
with col2:
    if st.button("Stop Game"):
        st.session_state.game_active = False

game_plot_placeholder = st.empty()

if st.session_state.game_active:
    st.session_state.ball_x += st.session_state.ball_vx
    st.session_state.ball_y += st.session_state.ball_vy
    
    if st.session_state.ball_x - ball_radius < 0:
        st.session_state.ball_x = ball_radius
        st.session_state.ball_vx *= -1
    
    if st.session_state.ball_x + ball_radius > game_width:
        st.session_state.ball_x = game_width - ball_radius
        st.session_state.ball_vx *= -1

    if st.session_state.ball_y + ball_radius > game_height:
        st.session_state.ball_y = game_height - ball_radius
        st.session_state.ball_vy *= -1

    if st.session_state.ball_y - ball_radius < 0:
        if(st.session_state.ball_x + ball_radius > paddle_x_position 
           and st.session_state.ball_x - ball_radius < paddle_x_position + paddle_width):
            st.session_state.ball_y = paddle_height + ball_radius
            st.session_state.ball_vy *= -1
        else:
            st.session_state.ball_y = ball_radius
            st.session_state.ball_vy *= -1

fig, ax = plt.subplots(figsize=(8, 4))
ax.set_xlim(0, game_width)
ax.set_ylim(0, game_height)
ax.set_aspect('equal', adjustable='box')
ax.axis('off')

paddle = plt.Rectangle(
    (paddle_x_position, 0),
    paddle_width,
    paddle_height,
    color='blue'
)
ax.add_patch(paddle)

ball = plt.Circle(
    (st.session_state.ball_x, st.session_state.ball_y),
    ball_radius,
    color='red'
)
ax.add_patch(ball)

with game_plot_placeholder:
    st.pyplot(fig)
    plt.close(fig)

if st.session_state.game_active:
    time.sleep(0.05)
    st.rerun()