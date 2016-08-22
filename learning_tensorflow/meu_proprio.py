from my_functions import *

SAMPLE = create_samples(60,2)

CENTROIDS = choose_random_centroids(SAMPLE, 2)
plot_initial_centroids(CENTROIDS)

for x in range(3):
    nearest_indices = assign_to_nearest(SAMPLE, CENTROIDS)
    CENTROIDS = update_centroids(SAMPLE,nearest_indices,len(CENTROIDS))
    print 'updated:'
    print CENTROIDS

    plot_sample(SAMPLE)
    plot_centroids(CENTROIDS)

    plt.show()
