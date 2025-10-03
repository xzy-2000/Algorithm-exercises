using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.EventSystems;

public class PlayerMove : MonoBehaviour {
		private NavMeshAgent playerAgent;
		private CharacterController characterController;

		[Header("Keyboard Movement")]
		public float keyboardSpeed = 3.5f;
		public float rotationSpeed = 10f;

		void Start() {
			playerAgent = GetComponent<NavMeshAgent>();
			characterController = GetComponent<CharacterController>();
		}

		void Update() {
			// WASD / Arrow keys movement (camera-relative)
			float h = Input.GetAxis("Horizontal");
			float v = Input.GetAxis("Vertical");
			Vector3 input = new Vector3(h, 0f, v);

			if (input.sqrMagnitude > 0.001f) {
				// Stop NavMeshAgent while moving with keys
				if (playerAgent != null)
					playerAgent.isStopped = true;

				// Make movement camera-relative
				Vector3 camForward = Camera.main.transform.forward;
				camForward.y = 0f;
				camForward.Normalize();
				Vector3 camRight = Camera.main.transform.right;
				camRight.y = 0f;
				camRight.Normalize();

				Vector3 moveDir = (camForward * v + camRight * h).normalized;

				if (characterController != null) {
					// Use CharacterController if available for smoother collisions
					characterController.SimpleMove(moveDir * keyboardSpeed);
				} else {
					transform.position += moveDir * keyboardSpeed * Time.deltaTime;
				}

				// Rotate toward movement direction
				if (moveDir.sqrMagnitude > 0.001f) {
					Quaternion targetRot = Quaternion.LookRotation(moveDir);
					transform.rotation = Quaternion.Slerp(transform.rotation, targetRot, rotationSpeed * Time.deltaTime);
				}

				// While using keyboard, skip mouse-click navigation this frame
				return;
			} else {
				if (playerAgent != null)
					playerAgent.isStopped = false;
			}

			// Point-and-click navigation / interaction
			if (Input.GetMouseButtonDown(0) && (EventSystem.current == null || !EventSystem.current.IsPointerOverGameObject())) {
				Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
				RaycastHit hit;
				bool isCollide = Physics.Raycast(ray, out hit);
				if (isCollide) {
					if (hit.collider.tag == "Ground") {
						if (playerAgent != null) {
							playerAgent.stoppingDistance = 0;
							playerAgent.SetDestination(hit.point);
						} else {
							transform.position = hit.point;
						}
					} else if (hit.collider.tag == "Interactable") {
						var interactable = hit.collider.GetComponent<InteractableObject>();
						if (interactable != null) {
							interactable.OnClick(playerAgent);
						} else {
							// fallback: move to the clicked point if no InteractableObject script is present
							if (playerAgent != null) {
								playerAgent.stoppingDistance = 0;
								playerAgent.SetDestination(hit.point);
							} else {
								transform.position = hit.point;
							}
						}
					}
				}
			}
		}
}

// Simple InteractableObject base class included to avoid missing type errors.
// Derive your own interactable objects from this and override OnClick as needed.
public class InteractableObject : MonoBehaviour {
		public float interactionDistance = 1.5f;

		// Called when player clicks this interactable. If a NavMeshAgent is supplied,
		// the agent will move to the object and stop at interactionDistance.
		public virtual void OnClick(NavMeshAgent agent) {
			if (agent != null) {
				agent.stoppingDistance = interactionDistance;
				agent.SetDestination(transform.position);
			}
		}
}
}

}
}
}
}
