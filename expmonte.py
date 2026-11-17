import numpy as np
import matplotlib.pyplot as plt

# Parameters
initial_N0 = 0  # Initial population
lambda_decay = 0.0255  # Decay constant
delta_N = 200  # Increment added every 3 seconds
time_end = 2000  # Total simulation time in seconds
delta_t = 1  # Time step in seconds

# Time steps
time_steps = np.arange(0, time_end, delta_t)

# Simulation variables
N = initial_N0  # Initial number of particles
N_history = []  # To store the population at each time step
lifetimes = []  # To store particle lifetimes (detected decays only)
decay_events = []  # To store decay times (detected decays only)
creation_events = []  # To track all particle creation times

# Track particles with their creation times
particles = []  # Each element is the creation time of a particle

# Variables for skipping logic
event_counter = 0  # To count addition events
skip_events = {14, 15}  # Events to skip within each minute

# Monte Carlo simulation
for t in time_steps:
    # Simulate decay
    surviving_particles = []
    for creation_time in particles:
        time_since_creation = t - creation_time
        if np.random.rand() < lambda_decay * delta_t:  # Particle decays
            # Apply 10% detection miss only for the first second after creation
            if time_since_creation <= 1 and np.random.rand() > 0.7:
                continue  # Miss the decay event (10%)
            
            # Record detected decay events
            lifetimes.append(time_since_creation)  # Record its lifetime
            decay_events.append(t)  # Record the detected decay event
            creation_events.append(creation_time)  # Track creation event
        else:
            surviving_particles.append(creation_time)  # Still alive
    
    particles = surviving_particles
    
    # Add new particles every 3 seconds
    if int(t) % 3 == 0 and t % 3 < delta_t:
        # Increment event counter and reset every minute
        event_counter = (event_counter + 1) % 20  # Adjust to track per 3s intervals
        
        # Skip the 14th and 15th addition events per minute
        if event_counter not in skip_events:
            particles.extend([t] * delta_N)  # Add `delta_N` particles with time `t`
    
    # Update current population
    N = len(particles)
    N_history.append(N)

# Compute uncorrelated time differences
uncorrelated_time_differences = []
num_samples = min(len(decay_events), len(creation_events))
random_decay_times = np.random.choice(decay_events, num_samples, replace=False)
random_creation_times = np.random.choice(creation_events, num_samples, replace=False)

for decay_time, creation_time in zip(random_decay_times, random_creation_times):
    uncorrelated_time_differences.append(decay_time - creation_time)

# Filter data for the zoomed-in range
lifetime_filtered = [lt for lt in lifetimes if -150 <= lt <= 150]
uncorrelated_filtered = [utd for utd in uncorrelated_time_differences if -150 <= utd <= 150]

# Plotting
plt.figure(figsize=(18, 6))

# Plot the population change over time
plt.subplot(1, 2, 1)
plt.plot(time_steps, N_history, label='Population (N)', color='green')
plt.axhline(initial_N0, color='r', linestyle='--', label='Initial $N_0$')
plt.xlabel('Time (s)')
plt.ylabel('Population (N)')
plt.title('Monte Carlo Simulation of Exponential Decay with Growing $N_0$ (Every 3 Seconds)')
plt.legend()
plt.grid()

# Plot the filtered lifetimes and uncorrelated background
plt.subplot(1, 2, 2)
plt.hist(lifetime_filtered, bins=np.arange(-150, 151, 1), color='orange', edgecolor='black', alpha=0.7, label='Lifetimes (Correlated, Detected)')
plt.hist(uncorrelated_filtered, bins=np.arange(-150, 151, 1), color='blue', edgecolor='black', alpha=0.5, label='Uncorrelated Differences')
plt.xlabel('Time Difference (s)')
plt.ylabel('Count')
plt.title('Lifetime Distribution with Uncorrelated Background (Zoomed)')
plt.legend()
plt.grid()

# Save the plot
output_filename = "simulation_results.png"
plt.tight_layout()
plt.savefig(output_filename, dpi=300)  # Save the figure as a high-quality PNG
plt.show()

print(f"Plot saved as '{output_filename}'")
