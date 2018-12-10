#include "KDTree.h"
#include <math.h>

KDNode::KDNode(double lat, double lon, const char *desc) {
    left = NULL;
    right = NULL;
    description = desc;
    latitude = lat;
    longitude = lon;
}

KDNode::~KDNode() {
}

// returns the distance (in miles) beween this node and a given lat and lon
double KDNode::distance(double lat, double lon) {
    double param = M_PI / 180.0; // required for conversion from degrees to radians
    double rad = 3956.0;  // radius of earth in miles
    double d_lat = (lat - latitude) * param;
    double d_lon = (lon - longitude) * param;
    double dist = sin(d_lat/2) * sin(d_lat/2) + cos(latitude*param) * cos(lat*param) * sin(d_lon/2) * sin(d_lon/2);
    dist = 2.0 * atan2(sqrt(dist), sqrt(1-dist));
    return rad * dist;
}

KDTree::KDTree() {
    root = NULL;
    size = 0;
}

KDTree::~KDTree() {
    destroy(root);
}


void KDTree::destroy(KDNode *p) {

    //base case
    if (p == NULL){
        return;
    }

    //recurse through tree
    destroy(p->left);
    destroy(p->right);

    //delete node
    delete p;
}


void KDTree::insert(double lat, double lon, const char *desc) {
    //node *p = new KDNode(lat, lon, desc);

    if (root == NULL){
        root = p;
        p->color = 0;
        return;
    }

    node *curr = root;
    bool currColor;

    while (curr != NULL){
        if (curr->color == 0){

            if (lat < curr->lat ){

                if (curr->left != NULL){
                    curr = curr->right;
                    currColor = 1;
                }
                else {
                    curr->left = new KDNode(lat, lon, desc);
                    p->color = 1;
                }
            }

            if (lat > curr->lat ){

                if (curr->right != NULL){
                    curr = curr->right;
                    currColor = 1;
                }
                else {
                    curr->right = new KDNode(lat, lon, desc);
                    p->color = 1;
                }
            }

        }

        if (curr->color == 1){

            if (long < curr->lat ){

                if (curr->left != NULL){
                    curr = curr->right;
                    currColor = 0;
                }
                else {
                    curr->left = new KDNode(lat, lon, desc);
                    p->color = 0;
                }
            }

            if (long > curr->lat ){

                if (curr->right != NULL){
                    curr = curr->right;
                    currColor = 0;
                }
                else {
                    curr->right = new KDNode(lat, lon, desc);
                    p->color = 0;
                }
            }

        }

    }




    // ********************************
    // TODO
    // need to increase size after each successful insertion
    // ********************************

}

//recursively test every value for latitude/ longitude?
unsigned int KDTree::printNeighbors(double lat, double lon, double rad, const char *filter) {
    // ********************************
    // TODO
    // ********************************
    return -1;
}

unsigned int KDTree::getSize() {
    // ********************************
    // TODO
    // ********************************
    return -1;
}

int main(){
    
}